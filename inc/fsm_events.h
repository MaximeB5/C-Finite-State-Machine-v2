#ifndef FSM_EVENTS_H
#define FSM_EVENTS_H

// My Includes
    // None for the moment.
    
// Includes
    // None for the moment.

// Defines
    // None for the moment.

typedef enum SystemEvent
{
	E4,
    E5,
    E6,
    E7,
    E8,
    last_Event
} eSystemEvent;

// Functions
eSystemEvent read_event(void);

#endif // FSM_EVENTS_H