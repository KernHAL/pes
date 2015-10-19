#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIMIT 1000

void find_pentagonals (int *pentagonals, int size);
void check_pentagonal_sums (int *pentagonals, int size);

int *pentagonals;

int main (int argc, char** argv)
{
    pentagonals = (int*) malloc(LIMIT * sizeof(int));
    printf("calculating pentagonals\n");
    find_pentagonals(pentagonals, LIMIT);
    printf("pentagonals calculated\n");
/*
    for (int i = 0; i < LIMIT; i++) {
        printf ("pentagonal p[%d]:%7d \n", (i+1), *pentagonals++);
    }
*/

//    free(pentagonals);
    printf("\n---------------------------\n");
    check_pentagonal_sums(pentagonals, LIMIT);

    return EXIT_SUCCESS;
}

void find_pentagonals(int* pentagonals, int size) {
    for (int i = 1; i <= LIMIT; i++) {
        int pentagonal = (i * (3*i -1)) / 2;
        *pentagonals++ = pentagonal;
    }
}

void check_pentagonal_sums(int *pentagonals, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                continue;

            int sum = pentagonals[i] + pentagonals[j];
            //printf("p[%d] + p[%d] = %d\n", i+1, j+1, sum);
            //printf("%d + %d = %d\n", pentagonals[i], pentagonals[j], sum);

            for(int index = (i<j)?(j):(i); index < LIMIT; index++){
            //printf("the index is: %d\n", index);

            if (sum == pentagonals[index]){
                printf("\n---------------------------\n");
                printf("Got it!\n");
                printf ("p[%d] + p[%d] = p[%d]\n", i, j, index);
                printf("\n---------------------------\n");
            }

            if (sum < pentagonals[index] )
                break;
            }
        }
    }
}
