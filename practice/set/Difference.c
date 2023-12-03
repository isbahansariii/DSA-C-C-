// Difference

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

void deleteAll(struct node *head)
{
    struct node *temp;
    while (head != NULL)
    {
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

int compare(int num)
{   
    struct node *S2 = set2;
    // if the number is not present in s1 then return 1
    // if the number is present in s1 then return 0
    while (S2 != NULL)
    {
        if (S2->number == num)
        {
            return 0;
        }
        S2 = S2->next;
    }
    return 1;
}

void difference(struct node *S1, struct node *S2){
    while(S1 != NULL){
        struct node *curr = S2;
        while(curr != NULL){
            if( compare(S1->number) ){
                insert3(S1->number);
                break;
            }
            curr = curr->next;
        }
        S1 = S1->next;
    }
}

int main()
{
    set1 = insert(set1, 1);
    set1 = insert(set1, 3);
    set1 = insert(set1, 4);
    set1 = insert(set1, 7);
    set1 = insert(set1, 12);
    printf("Set#1: ");
    display(set1);

    set2 = insert(set2, 1);
    set2 = insert(set2, 5);
    set2 = insert(set2, 7);
    set2 = insert(set2, 9);
    printf("\nSet#2: ");
    display(set2);

    difference(set1, set2);
    printf("\nDifference of set#1 and set#2: ");
    display(set3);
}