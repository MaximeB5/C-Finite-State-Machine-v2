// My Includes
#include "../inc/fsm.h"

// Includes
#include <stdio.h>
#include <stdlib.h>

// My Defines
// For a FSM where all non-linear transitions are declared separately, just like the linear ones
#define FSM_SIZE_V1 11
// For a FSM where all non-linear group of transitions are set together
#define FSM_SIZE_V2 8

int main()
{
	printf("Hello from C-Finite State Machine-v2.\n");
	printf("This FSM follows a non-linear sequence of 8 states. There are 5 events, from 4 to 8.\n\n");

	// Declare all the transitions that compose the FSM.
	// Linear means this is a direct and logical link between each state, non-linear means there are several options.
	// For a better readibility and to avoid 'oups I forgot to init this one' issue, I suggest to initialize each Transition right after declaring it.
	
	// Comment the version of the FSM you want to use. By default, this code aims to play with the V1.
	
	/* This version uses FSM_SIZE_V1 */
	// Linear
	Transition trans_1_2;	initialize(&trans_1_2, P1, 1, NO_EVENT, ret_p2);
	Transition trans_2_3;	initialize(&trans_2_3, P2, 1, NO_EVENT, ret_p3);

	// Non-linear
	Transition trans_3_4;	initialize(&trans_3_4, P3, 1, E4, ret_p4);
	Transition trans_3_5;	initialize(&trans_3_5, P3, 1, E5, ret_p5);
	Transition trans_3_6;	initialize(&trans_3_6, P3, 1, E6, ret_p6);

	// Linear
	Transition trans_4_3;	initialize(&trans_4_3, P4, 1, NO_EVENT, ret_p3);
	Transition trans_5_2;	initialize(&trans_5_2, P5, 1, NO_EVENT, ret_p2);

	// Non-linear
	Transition trans_6_7;	initialize(&trans_6_7, P6, 1, E7, ret_p7);
	Transition trans_6_8;	initialize(&trans_6_8, P6, 1, E8, ret_p8);

	// Linear
	Transition trans_7_3;	initialize(&trans_7_3, P7, 1, NO_EVENT, ret_p3);
	Transition trans_8_2;	initialize(&trans_8_2, P8, 1, NO_EVENT, ret_p2);
	
	/* This version uses FSM_SIZE_V2 */
	/*
	// Linear
	Transition trans_1_2;	initialize(&trans_1_2, P1, 1, NO_EVENT, ret_p2);
	Transition trans_2_3;	initialize(&trans_2_3, P2, 1, NO_EVENT, ret_p3);

	// Non-linear
	Transition trans_3;	initialize(&trans_3_4, P3, 3, E4, E5, E6, ret_p4, ret_p5, ret_p6);

	// Linear
	Transition trans_4_3;	initialize(&trans_4_3, P4, 1, NO_EVENT, ret_p3);
	Transition trans_5_2;	initialize(&trans_5_2, P5, 1, NO_EVENT, ret_p2);

	// Non-linear
	Transition trans_6;	initialize(&trans_6_7, P6, 2, E7, E8, ret_p7, ret_p8);

	// Linear
	Transition trans_7_3;	initialize(&trans_7_3, P7, 1, NO_EVENT, ret_p3);
	Transition trans_8_2;	initialize(&trans_8_2, P8, 1, NO_EVENT, ret_p2);
	*/


	// Create the FSM
	/* This version uses FSM_SIZE_V1 */
	Transition FSM [FSM_SIZE_V1] =
	{
		// Linear
		trans_1_2,
		trans_2_3,

		// Non-linear
		trans_3_4,
		trans_3_5,
		trans_3_6,

		// Linear
		trans_4_3,
		trans_5_2,

		// Non-linear
		trans_6_7,
		trans_6_8,

		// Linear
		trans_7_3,
		trans_8_2

	};
	
	/* This version uses FSM_SIZE_V2 */
	/*
	Transition FSM [FSM_SIZE_V2] =
	{
		// Linear
		trans_1_2,
		trans_2_3,

		// Non-linear
		trans_3,

		// Linear
		trans_4_3,
		trans_5_2,

		// Non-linear
		trans_6,

		// Linear
		trans_7_3,
		trans_8_2

	};
	*/
/*
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
*/
	// Free the memory of each transition
	unsigned int i = 0;
	for(i = 0; i < FSM_SIZE_V1; ++i) {
		destroy( &FSM[i] );
	}

	// I hope you freed the memory you allocated before exiting the program, because if not, you'll enjoy your memory leaks all alone lmao.
	return(0);
}
