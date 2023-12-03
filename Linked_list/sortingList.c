#include<stdio.h>>
#include<stdlib.h>

struct list3{
	int number;
	struct list3* next;
	struct list3* prev;
};

struct list3* start3 = NULL;

void sort_list3() {
    struct list3* curr = start3; // Initialize a pointer to the start of list3
    struct list3* nextNode;

    int swapped, temp;

    // Perform the Bubble Sort algorithm
    do {
        swapped = 0;
        curr = start3;

        while (curr->next != NULL) {
            nextNode = curr->next;

            // Compare adjacent elements and swap them if they are in the wrong order
            if (curr->number > nextNode->number) {
                temp = curr->number;
                curr->number = nextNode->number;
                nextNode->number = temp;
                swapped = 1; // Flag to indicate that a swap occurred
            }
            curr = curr->next; // Move to the next element in list3
        }
    } while (swapped); // Continue sorting until no more swaps are needed
}
