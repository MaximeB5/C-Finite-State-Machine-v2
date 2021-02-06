#ifndef FSM_EVENTS_H
#define FSM_EVENTS_H

// My Includes
    // None for the moment.
    
// Includes
    // None for the moment.

// Defines
    // None for the moment.

// Events of the FSM
typedef enum SystemEvent
{
    NO_EVENT,
	E4,
    E5,
    E6,
    E7,
    E8,
    last_Event
} eSystemEvent;


// Functions
// Default read event
eSystemEvent read_event     (void);

// Customs read event
eSystemEvent read_event_P3  (void);
eSystemEvent read_event_P6  (void);

#endif // FSM_EVENTS_H