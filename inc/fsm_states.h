#ifndef FSM_STATES_H
#define FSM_STATES_H

// My Includes
    // None.

// Includes
    // None.

// Defines
    // None.

// States of the FSM
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


// Functions
// Event handlers
eSystemState ret_p1(void);
eSystemState ret_p2(void);
eSystemState ret_p3(void);
eSystemState ret_p4(void);
eSystemState ret_p5(void);
eSystemState ret_p6(void);
eSystemState ret_p7(void);
eSystemState ret_p8(void);

#endif // FSM_STATES_H