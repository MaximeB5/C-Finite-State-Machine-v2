// My Includes
#include "../inc/fsm.h"

// Includes
#include <stdio.h>
#include <stdlib.h>

// My Defines
// For a FSM where all non-linear group of transitions are set together. This number depends on the total number of transitions in the FSM.
#define FSM_SIZE 8

int main()
{
	printf("Hello from C-Finite State Machine-v2.\n");
	printf("This FSM follows a non-linear sequence of 8 states. There are 5 events, from 4 to 8.\n\n");

	// Declare all the transitions that compose your FSM.
	// Linear means this is a direct and logical link between each state, non-linear means there are several options.
	// For a better readibility and to avoid 'oups I forgot to init this one' issue, I suggest to initialize each Transition right after declaring it.
	
	// Linear
	Transition trans_1;		initialize(&trans_1, P1, 1, NO_EVENT, ret_p2);
	Transition trans_2;		initialize(&trans_2, P2, 1, NO_EVENT, ret_p3);

	// Non-linear
	Transition trans_3;		initialize(&trans_3, P3, 3, E4, E5, E6, ret_p4, ret_p5, ret_p6);

	// Linear
	Transition trans_4;		initialize(&trans_4, P4, 1, NO_EVENT, ret_p3);
	Transition trans_5;		initialize(&trans_5, P5, 1, NO_EVENT, ret_p2);

	// Non-linear
	Transition trans_6;		initialize(&trans_6, P6, 2, E7, E8, ret_p7, ret_p8);

	// Linear
	Transition trans_7;		initialize(&trans_7, P7, 1, NO_EVENT, ret_p3);
	Transition trans_8;		initialize(&trans_8, P8, 1, NO_EVENT, ret_p2);


	// Create the FSM
	Transition FSM [FSM_SIZE] =
	{
		// Linear
		trans_1,
		trans_2,

		// Non-linear
		trans_3,

		// Linear
		trans_4,
		trans_5,

		// Non-linear
		trans_6,

		// Linear
		trans_7,
		trans_8

	};


	// --- The FSM working logic is implemented below ---

	// Init your FSM with the 1st state it'll begin with.
	eSystemState next_state = P1;

	// Working loop : that's here we implements how we wants the FSM to work.
	// We have 2 options at each iteration : either we have an event that must occurs, or we don't have one.
	// This information is known thanks to the NO_EVENT value.
	while(1)
	{
		// Global check if we're in a valid state and all.
		if( next_state < last_State						// For whatever obscure reasons the state goes beyond the limits of the tab that is the FSM.
		&& FSM[next_state]._event_handlers != NULL )	// If we try to access a state that has be freed, the handlers aren't valid anymore.
		{
			// If we have an event to deal with, we have to read it and check its value is valid.
			if( FSM[next_state]._events[0] != NO_EVENT )
			{
				// Get the event.
				eSystemEvent eNewEvent;

				// Add an if statement for each non-linear transition of your FSM.
				if		(FSM[next_state]._state == P3)	eNewEvent = read_event_P3();
				else if	(FSM[next_state]._state == P6)	eNewEvent = read_event_P6();
				else									eNewEvent = last_Event;	// Default case leading to an input error.

				// Debug.
				printf("State is %d\n", eNewEvent);

				unsigned int event_index = last_Event;	// Default value that is safe input.
				
				// Check if the event exists for the current transition, if yes, it updates the event_index for the normal scenario.
				unsigned int i = 0;
				for(i = 0; i < FSM[next_state]._nb_of_events; ++i) {
					if(FSM[next_state]._events[i] == eNewEvent)
					{
						event_index = i;

						// Debug.
						printf("ok event index is '%u'\n", i);

						break;
					}
				}

				// Check if the event exists for the current transition.
				if( eNewEvent < last_Event		// For whatever obscure reasons the event goes beyond the limits of the tab that is the FSM.
				&& event_index < last_Event	)	// If the event exists for the current transition.
				{
					// Update the next state variable with the value returned by the handler.
					next_state = (*FSM[next_state]._event_handlers[event_index])();
				}
				// Invalid event as input.
				else
				{
					printf("--- Invalid Event Input ---\nExit...\n\n");
					break;
				}
			}
			// Else, we just call the current event handler that'll do its work before leading to the next state.
			// We do not have to wait for a specific event since there is none to wait. 
			else
			{
				// Update the next state variable with the value returned by the handler.
				next_state = (*FSM[next_state]._event_handlers[NO_EVENT])();
			}
		}
		else
		{
			printf("--- Global Check failed ---\nExit...\n\n");
			break;
		}
	} // End of the working loop.


	// Free the memory of each transition
	unsigned int i = 0;
	for(i = 0; i < FSM_SIZE; ++i) {
		destroy( &FSM[i] );
	}

	// I hope you correctly freed the memory you allocated before exiting the program, because if not, you'll enjoy your memory leaks all alone lmao.
	return(0);
}
