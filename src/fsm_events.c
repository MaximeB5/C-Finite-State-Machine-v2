// My Includes
#include "../inc/fsm_events.h"
    
// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines
#define LINE_SIZE 3
#define NB_OF_VAL 1

/**
 * @brief Default Read Event used in the linear FSM.
 * 
 * @return eSystemEvent 
 */
eSystemEvent read_event(void)
{
    printf("Enter the number of the event :\n\t0 -> Card_Insert_Event\n\t1 -> Pin_Enter_Event\n\t2 -> Option_Selection_Event\n\t3 -> Amount_Enter_Event\n\t4 -> Amount_Dispatch_Event\n\tother -> Error\n");

    char line[LINE_SIZE];

    // Fgets error
    if( fgets(line, LINE_SIZE, stdin) == NULL )
    {
        printf("\t\t--- ERROR EOF STDIN (1) in read_event ---\n");
        return last_Event;
    }

    char format[LINE_SIZE];
    sprintf(format, "%%d");

    int user_input;

    // Invalid user input
    if( sscanf(line, format, &user_input) != NB_OF_VAL)
    {
        printf("\t\t--- ERROR Invalid User Input in read_event ---\n");
        return last_Event;
    }

    // If the input line is too long
    if( (strlen(line) == LINE_SIZE - 1) && (line[LINE_SIZE-2] != '\n') )
    {
        char c;
        do { c =getchar(); } while(c != '\n');
    }

    // Input stream error
    if( feof(stdin) )
    {
        printf("\t\t--- ERROR EOF STDIN (2) in read_event ---\n");
        return last_Event;
    }

    switch (user_input)
    {
        case 4:
            return E4;
            break;

        case 5:
            return E5;
            break;
        
        case 6:
            return E6;
            break;

        case 7:
            return E7;
            break;

        case 8:
            return E8;
            break;

        case 0:
        case 1:
        case 2:
        case 3:
        default:
            return last_Event;
            break;
    }
}


/**
 * @brief Custom Read Event for the transition P3
 * 
 * @return eSystemEvent 
 */
eSystemEvent read_event_P3(void)
{
    printf("Enter the number of the event :\n\t1 -> Go to transition P4\n\t2 -> Go to transition P5\n\t3 -> Go to transition P6\n\tother -> Error\n");

    char line[LINE_SIZE];

    // Fgets error
    if( fgets(line, LINE_SIZE, stdin) == NULL )
    {
        printf("\t\t--- ERROR EOF STDIN (1) in read_event ---\n");
        return last_Event;
    }

    char format[LINE_SIZE];
    sprintf(format, "%%d");

    int user_input;

    // Invalid user input
    if( sscanf(line, format, &user_input) != NB_OF_VAL)
    {
        printf("\t\t--- ERROR Invalid User Input in read_event ---\n");
        return last_Event;
    }

    // If the input line is too long
    if( (strlen(line) == LINE_SIZE - 1) && (line[LINE_SIZE-2] != '\n') )
    {
        char c;
        do { c =getchar(); } while(c != '\n');
    }

    // Input stream error
    if( feof(stdin) )
    {
        printf("\t\t--- ERROR EOF STDIN (2) in read_event ---\n");
        return last_Event;
    }

    switch (user_input)
    {
        case 1:
            return E4;
            break;

        case 2:
            return E5;
            break;
        
        case 3:
            return E6;
            break;        

        case 0:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            return last_Event;
            break;
    }
}


/**
 * @brief Custom Read Event for the transition P6
 * 
 * @return eSystemEvent 
 */
eSystemEvent read_event_P6(void)
{
    printf("Enter the number of the event :\n\t4 -> Go to transition P7\n\t5 -> Go to transition P8\n\tother -> Error\n");

    char line[LINE_SIZE];

    // Fgets error
    if( fgets(line, LINE_SIZE, stdin) == NULL )
    {
        printf("\t\t--- ERROR EOF STDIN (1) in read_event ---\n");
        return last_Event;
    }

    char format[LINE_SIZE];
    sprintf(format, "%%d");

    int user_input;

    // Invalid user input
    if( sscanf(line, format, &user_input) != NB_OF_VAL)
    {
        printf("\t\t--- ERROR Invalid User Input in read_event ---\n");
        return last_Event;
    }

    // If the input line is too long
    if( (strlen(line) == LINE_SIZE - 1) && (line[LINE_SIZE-2] != '\n') )
    {
        char c;
        do { c =getchar(); } while(c != '\n');
    }

    // Input stream error
    if( feof(stdin) )
    {
        printf("\t\t--- ERROR EOF STDIN (2) in read_event ---\n");
        return last_Event;
    }

    switch (user_input)
    {
        case 4:
            return E7;
            break;

        case 5:
            return E8;
            break;

        case 0:
        case 1:
        case 2:
        case 3:
        case 6:
        case 7:
        case 8:
        default:
            return last_Event;
            break;
    }
}