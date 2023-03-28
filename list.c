#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

// Add node to a linked list 
node_t *addNode(node_t *head, data_t *d) {
    node_t *newNode = malloc(sizeof(node_t));
    newNode->data = d;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        node_t *nextNode = head;
        while (nextNode->next != NULL) {
            nextNode = nextNode->next;
        }
        nextNode->next = newNode;
    }
    return head;
}

// Search the linked list for element that matches the address 
void searchLinkedList(node_t *head, char *address, FILE *file) {
    node_t *current = head;
    int count = 0;
    fprintf(file, "%s\n", address);
    while (current != NULL) {
        if (strcmp(current->data->address, address) == 0) {
            printData(current->data, file);
            count++;
        }
        current = current->next;
    }

    if (count > 0) {
        printf("%s --> %d\n", address, count);
    }
    else {
        printf("%s --> NOTFOUND\n", address);
    }
}

/* Create an array that stores the node of the linked list,
   Sorts the array and then output the data */
void sortArray(node_t *head, int size, double grade, FILE *file) {
    int i = 0;
    node_t *sortedArray[size];
    node_t *current = head;
    while (current != NULL) {
        sortedArray[i] = current;
        current = current->next;
        i++;
    }
    bubbleSort(sortedArray, size);
    fprintf(file, "%g\n", grade);
    data_t *match = binarySearch(sortedArray, size, grade)->data;
    printData(match, file);
    printf("%g -> %g\n", grade, match->grade1in);
}

/* Sort the array
   Edited From: https://www.geeksforgeeks.org/bubble-sort/ */
void bubbleSort(node_t *A[], int size) {
    node_t *temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (A[j]->data->grade1in > A[j + 1]->data->grade1in) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

/* Search the array of linked list for the closest element to the target
   Edited From: https://www.geeksforgeeks.org/find-closest-number-array/ */
node_t *binarySearch(node_t *A[], int size, double grade) {
    int left = 0, mid = 0;
    int right = size;

    // Search the left most element of the array
    if (grade <= A[0]->data->grade1in) {
        return A[0];
    }
    // Search the right most element of the array
    if (grade >= A[size - 1]->data->grade1in) {
        return A[size - 1];
    }

    // Begin Binary Search
    while(left < right){
        mid = (left + right) / 2;
        if (A[mid]->data->grade1in == grade){
            return A[mid];
        }
        // Search left side of array if target is less than the middle element
        if(grade < A[mid]->data->grade1in) {
            if (mid > 0 && grade > A[mid-1]->data->grade1in) {
                // Determine the closest value
                if (grade - A[mid-1]->data->grade1in >= A[mid]->data->grade1in - grade) {
                    return A[mid];
                }
                else {
                    return A[mid-1];
                }
            }
            right = mid;
        }
        else
        {
            if (mid < size - 1 && grade < A[mid + 1]->data->grade1in) {
                // Determine the closest value
                if (grade - A[mid]->data->grade1in >= A[mid+1]->data->grade1in - grade) {
                    return A[mid+1];
                }
                else {
                    return A[mid];
                }
            }
            left = mid + 1;
        }
    }
    return A[mid];
}

// Free the memory of all the node and string 
void freeNode(node_t *head) {
    node_t *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->data->address);
        free(tmp->data->clue_sa);
        free(tmp->data->asset_type);
        free(tmp->data->segside);
        free(tmp);
    }
}

