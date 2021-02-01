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
eSystemState p1_handler(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P1; }
eSystemState p2_handler(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P2; }
eSystemState p3_handler(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P3; }
eSystemState p4_handler(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P4; }
eSystemState p5_handler(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P5; }
eSystemState p6_handler(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P6; }
eSystemState p7_handler(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P7; }
eSystemState p8_handler(void) { printf("Event called is '%s'\n\n", __FUNCTION__);   return P8; }

#endif // FSM_STATES_H