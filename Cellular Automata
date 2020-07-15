#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 100
#define GENERATION_COUNT 50
#define NULL_CHAR '_' // This is for dead cells.
#define FULL_CHAR '#' // This is for alive cells.

void print_state(int state_to_print[ ], int state_length);
void initialize_array(int array_to_initialize[ ], int state_length);
void swap_arrays(int current_state[ ], int next_state[ ]);
void search_the_state(int look_up[ ][ 2 ], int new_state [], int index_current_generation, int state_indice);
void calculate_next_state(int current_state[ ], int next_state[ ], int lookup_table[ ][ 2 ]);

void main ()
{
    int state = 0;
	int CurrentState[ARRAY_LENGTH];
	int nextState[ARRAY_LENGTH];
	int lookUpTable[8][2] = { {0, 0}, {1, 1}, {10, 1}, {11, 1}, {100, 1}, {101, 0}, {110, 0}, {111, 0} }; // We use 2D arrays for applying rule 30 look up table.
    
    printf("Cellular automaton by applying rule 30 look up table is: \n");
    
    initialize_array(CurrentState, ARRAY_LENGTH);
    initialize_array(nextState, ARRAY_LENGTH);
    CurrentState[ARRAY_LENGTH / 2 - 1] = 1;
    print_state(CurrentState, ARRAY_LENGTH);
    
    while (state++ < GENERATION_COUNT) // It determines how many lines does it take and arranges it.
    {
        calculate_next_state(CurrentState, nextState, lookUpTable);
    }
    
    printf("\n");
    
    system("PAUSE");
}

// The function below places appropriate characters and prints them. ('-' or '#') 

void print_state(int state_to_print[ ], int state_length)
{
    int i;
    
    for (i=0; i < state_length; ++i)
    {
        if (state_to_print[i] == 0)
        printf ( "%c", NULL_CHAR );
        else
        printf ( "%c", FULL_CHAR );
    }
    printf ( "\n" );
}

// The function below fills all the arrays with '0' so that it can make prepare them to use. 
 
void initialize_array(int array_to_initialize[ ], int state_length)
{
    int i;
    
    for (i=0; i < state_length; ++i)
    {
        array_to_initialize[i] = 0;
    }
}

// The function below makes swap operation between two arrays. By using global variables, it creates a generic code.

void swap_arrays(int current_state[ ], int next_state[ ])
{
    int i;
    
    for (i=1; i < ARRAY_LENGTH; ++i)
    {
        current_state[i] = next_state[i];
    }
}
 
// The function below takes the neighbour numbers from rule 30 look up table and assigns them into new state.
 
void search_the_state(int look_up[ ][2], int new_state [ ], int index_current_generation, int state_indice)
{
    int lookup_iterator;
    
    for (lookup_iterator = 0; lookup_iterator < ARRAY_LENGTH; ++lookup_iterator)
    {
        if (state_indice == look_up[lookup_iterator][0])
        {
            new_state[index_current_generation] = look_up[lookup_iterator][1];
            break;
        }
    }
}
 
// The function below uses current state array and next state array. By applying the rule 30 look up table, it fills the next state and prints it.
// Finally, it calls swap function to apply it between current state and next state.

void calculate_next_state(int current_state[ ], int next_state[ ], int lookup_table[ ][2])
{
    int i;
    
    for (i=1; i < ARRAY_LENGTH; ++i)
    {
        int state_indice = 0;
        state_indice += 100 * current_state[i-1];
        state_indice += 10 * current_state[i];
        state_indice += current_state[i+1];
        search_the_state(lookup_table, next_state, i, state_indice);
    }
    
    print_state(next_state, ARRAY_LENGTH);
    swap_arrays(current_state, next_state);
}
