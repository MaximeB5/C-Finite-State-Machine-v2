// My Includes
#include "../inc/fsm.h"

// Includes
#include <stdio.h>
#include <stdlib.h>

// My Defines
	// None for the moment.

int main()
{
	printf("Hello from C-Finite State Machine-v2.\n");
	printf("This FSM follows a non-linear sequence of 8 states. There are 5 events, from 4 to 8.\n\n");

	// Declare all the transitions that compose the FSM.
	// Linear means this is a direct and logical link between each state, non-linear means there are several options.
	// Linear						
	Transition trans_1_2;
	Transition trans_2_3;

	// Non-linear
	Transition trans_3_4;
	Transition trans_3_5;
	Transition trans_3_6;

	// Linear
	Transition trans_4_3;
	Transition trans_5_2;

	// Non-linear
	Transition trans_6_7;
	Transition trans_6_8;

	// Linear
	Transition trans_7_3;
	Transition trans_8_2;

	// Initialize each transition
	initialize(&trans_1_2, P1, 1);	// TODO : jsais pas si c'est une bonne idée ou pas, mais go ajouter à la fonction 2 listse d'arguments variables pour les events et leurs handlers associés


	// Create the FSM
	Transition FSM [] =
	{
		/*{Idle_State,			Card_Insert_Event,		insert_card_handler},*/
		
	};

	// Init with the 1st state
	eSystemState next_state = P1;

	// Working loop			// TODO
	while(1)
	{
		// Get event
		eSystemEvent eNewEvent = read_event();
		printf("State is %d\n", eNewEvent);

        if(		(next_state < last_State)
			&&	(eNewEvent < last_Event)
			&&	(FSM[next_state].events == eNewEvent)
			&&	(FSM[next_state].event_handlers != NULL)
		)
		{
            // Function call as per the state and event and return the next state of the finite state machine
            next_state = (*FSM[next_state].event_handlers)();
		}
        else
		{
			printf("--- invalid input ---\n\n");
		}
	}

	// Free the memory of each transition
		// TODO

	return(0);
}
