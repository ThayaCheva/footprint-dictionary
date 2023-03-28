#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"
#include "data.h"

/* main.c
*
* Created by Thaya Chevaphatrakul (tchevaphatra.unimelb.edu.au) 8/17/2022
* 
* A program that create and uses a dictionary based on a linked list to store and search
* information about the footpaths in the City of Melbourne
* 
* To run the program for stage 1
* ./dict1 1 tests/dataset_1.csv output.out < tests/test1.s1.in > output.stdout.out
* To run the program for stage
* ./dict2 2 tests/dataset_1.csv output.out < tests/test1.s2.in > output.stdout.out
*/

int main(int argc, char *argv[]) {
    FILE *inFile = fopen(argv[2], "r");
    FILE *outFile = fopen(argv[3], "w");
    assert(inFile);
    assert(outFile);
    int stage;
    char address[MAX_CSV+1][MAX_STRING];
    double grade;
    data_t data[MAX_CSV+1];
    sscanf(argv[1], "%d", &stage);
    // Count the number of elements in the csv file
    int n = buildArray(data, inFile);
    node_t *head = NULL;

    // Add data to linked list
    for (int i = 0; i < n; i++) {
        head = addNode(head, &data[i]);
    }

    // Stage 1
    if (stage == 1) {
        // Count the size of the input
        int size = read_strings(address);
        for (int i = 0 ; i < size; i++) {
            searchLinkedList(head, address[i], outFile);
        }
    }
    // Stage 2
    else {
        while (scanf("%lf", &grade) == 1) {
            sortArray(head, n, grade, outFile);
        }
    }
    
    freeNode(head);
    fclose(inFile);
    fclose(outFile);
}





