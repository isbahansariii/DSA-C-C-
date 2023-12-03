// Merge

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};
struct node *set1 = NULL;
struct node *set2 = NULL;
struct node *set3 = NULL;

struct node *insert(struct node *head, int Number)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;
    newnode->number = Number;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = current = newnode;
        return head;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
    current = newnode;
    return head;
}

struct node *Delete(struct node *head, int Number)
{

    struct node *prev = NULL;
    struct node *current = head;

    while (current != NULL && current->number != Number)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return head;
    }
    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
    return head;
}

void deleteAll(struct node *head){
    struct node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void display(struct node *head)
{
    // struct course *current = (struct course*)malloc(sizeof(struct course));
    struct node *current = head;
    if (current == NULL)
    {
        printf("\nNo List is available.");
        return;
    }
    while (current != NULL)
    {
        printf("\t%d", current->number);
        current = current->next;
    }
}

struct node *insert3(int Number)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *current = set3;
    newnode->number = Number;
    newnode->next = NULL;

    if (set3 == NULL)
    {
        set3 = current = newnode;
        return set3;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
    current = newnode;
    return set3;
}

void merge(struct node *S1, struct node *S2)
{
    while (S1 != NULL)
    {
        insert3(S1->number);
        S1 = S1->next;

    }
    while (S2 != NULL)
    {
        insert3(S2->number);
        S2 = S2->next;
    }
}

void sort_list3()
{
    struct node *curr = set3; // Initialize a pointer to the start of list3
    struct node *nextNode;

    int swapped, temp;

    // Perform the Bubble Sort algorithm
    do
    {
        swapped = 0;
        curr = set3;

        while (curr->next != NULL)
        {
            nextNode = curr->next;

            // Compare adjacent elements and swap them if they are in the wrong order
            if (curr->number > nextNode->number)
            {
                temp = curr->number;
                curr->number = nextNode->number;
                nextNode->number = temp;
                swapped = 1; // Flag to indicate that a swap occurred
            }
            curr = curr->next; // Move to the next element in list3
        }
    } while (swapped); // Continue sorting until no more swaps are needed
}

int main()
{
    set1 = insert(set1, 4);
    set1 = insert(set1, 18);
    set1 = insert(set1, 108);
    set1 = insert(set1, 8);
    set1 = insert(set1, 8);
    set1 = insert(set1, 80);
    printf("Set#1: ");
    display(set1);

    set2 = insert(set2, 14);
    set2 = insert(set2, 8);
    set2 = insert(set2, 80);
    printf("\nSet#2: ");
    display(set2);

    merge(set1, set2);
    printf("\nMerge of set#1 and set#2: ");
    sort_list3();
    display(set3);
}