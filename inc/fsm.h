#ifndef FSM_H
#define FSM_H

// My Includes
#include "fsm_states.h"
#include "fsm_events.h"

// Includes
    // None for the moment.

// Defines
    // None for the moment.

/**
 * @brief This struct represents a non-linear FSM
 * @param state the current state
 * @param nb_of_events the number of events, that's the memory size that'll be allocated for events and event_handlers
 * @param events the events dynamically allocated
 * @param event_handlers the event handlers dynamically allocated
 * 
 */
typedef struct FSM
{
    eSystemState        _state;
    unsigned int        _nb_of_events;
    eSystemEvent*       _events;
    pf_eventHandler*    _event_handlers;
} Transition;

// Functions
void initialize     (Transition * transition, const eSystemState state, const unsigned int nb_events, ...);
void destroy        (Transition * transition);

#endif // FSM_H