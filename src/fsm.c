// My Includes
#include "../inc/fsm.h"

// Includes
#include <stdlib.h>
#include <stdarg.h>

// My Defines
	// None for the moment.

/**
 * @brief initialize all the members of the transisition argument and allocate dynamic memory
 * CAUTION : it's up to the user's responsability to check the number of arguments he passed to the variable arguments list is correct.
 * The argument nb_events means "I will pass nb_event eSystemEvent and pf_eventHandler".
 * If you do shit with my function, I don't care, you're responsible, not me, I warnt you bitch.
 * It'll be undefined behavior, crash program, and so on. Good luck.
 * 
 * Example of what you can do : For nb_event = 2, so the variable arguments list must consist of 2 eSystemEvent and 2 pf_eventHandler (in this order).
 * 
 * @param transition 
 * @param state 
 * @param nb_events
 */
void initialize(Transition * transition, const eSystemState state, const unsigned int nb_events, ...)
{
    // https://stackoverflow.com/questions/17250480/declaring-int-array-inside-struct -> https://stackoverflow.com/a/21363967

    transition->_events         = (eSystemEvent*)    malloc( sizeof(eSystemEvent)    * nb_events );
    transition->_event_handlers = (pf_eventHandler*) malloc( sizeof(pf_eventHandler) * nb_events );
    transition->_state          = state;
    transition->_nb_of_events   = nb_events;

    va_list args;
    va_start(args, nb_events);
    
    unsigned int i = 0;

    // Events
    for(i = 0; i != nb_events; ++i) {
        transition->_events[i] = va_arg(args, eSystemEvent);
    }

    // Handlers
    for(i = 0; i != nb_events; ++i) {
        transition->_event_handlers[i] = va_arg(args, pf_eventHandler);
    }

    va_end(args);
}


/**
 * @brief free the dynamic memory allocated at the initialization for the members of the transition argument
 * 
 * @param transition 
 */
void destroy(Transition * transition)
{
    // https://stackoverflow.com/questions/17250480/declaring-int-array-inside-struct -> https://stackoverflow.com/a/21363967

    free(transition->_events);
    free(transition->_event_handlers);

    transition->_events         = NULL;
    transition->_event_handlers = NULL;
}