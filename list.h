#ifndef _LIST_H_
#define _LIST_H_

#include "data.h"

struct node {
    data_t *data;
    struct node* next;
}; 
typedef struct node node_t;

node_t *addNode(node_t *head, data_t *d);
node_t *binarySearch(node_t *A[], int size, double grade);
void freeNode(node_t *head);
void bubbleSort(node_t *A[], int size);
void searchLinkedList(node_t *head, char *address, FILE *file);
void sortArray(node_t *head, int size, double grade, FILE *file);

#endif
