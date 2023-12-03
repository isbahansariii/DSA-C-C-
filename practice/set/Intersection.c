// Intersecttion

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


void Insertion(struct node *S1, struct node *S2)
{   
    while (S1 != NULL)
    {
        struct node *curr = set2;
        while (curr != NULL)
        {
            if (S1->number == curr->number)
            {
                set3 = insert3(S1->number);
            }
            curr = curr->next;
        }
        S1 = S1->next;
    }
}

int main()
{
    set1 = insert(set1, 4);
    set1 = insert(set1, 18);
    set1 = insert(set1, 10);
    set1 = insert(set1, 8);
    set1 = insert(set1, 80);
    printf("Set#1: ");
    display(set1);

    set2 = insert(set2, 14);
    set2 = insert(set2, 8);
    set2 = insert(set2, 80);
    printf("\nSet#2: ");
    display(set2);

    Insertion(set1, set2);
    printf("\nInsertion of set#1 and set#2: ");
    display(set3);
}