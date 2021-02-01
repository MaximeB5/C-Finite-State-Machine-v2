#ifndef FSM_STATES_H
#define FSM_STATES_H

// My Includes
    // None for the moment.

// Includes
#include <stdio.h>

// Defines
    // None for the moment.

typedef enum SystemState
{
    P1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7,
    P8,
    last_State
} eSystemState;


// Typedef of function pointer
typedef eSystemState (*pf_eventHandler)(void);


// Event handlers
eSystemState ret_p1(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P1; }
eSystemState ret_p2(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P2; }
eSystemState ret_p3(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P3; }
eSystemState ret_p4(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P4; }
eSystemState ret_p5(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P5; }
eSystemState ret_p6(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P6; }
eSystemState ret_p7(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P7; }
eSystemState ret_p8(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P8; }

#endif // FSM_STATES_H