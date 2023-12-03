#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};
struct node*head = NULL;

void insert(int Number)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;
    newnode->number = Number;
    newnode->next = NULL;

    // If there is no node, add one node
    if (head == NULL)
    {
        head = current = newnode;
        return;
    }

    // If it is one node, add another node
    if (head->next == NULL)
    {
        // insert at last
        current->next = newnode;
        current = newnode;
        return;
    }

    // while (current->next != NULL)
    // {
    //     current = current->next;
    // }
    // current->next = newnode;
    // current = newnode;
}

void Delete(int Number){

    struct node *prev = NULL;
    struct node *current = head;

    while(current != NULL && current->number !=Number){
        prev = current;
        current = current->next;
    }
    if(current==NULL){
        printf("%d number not found.", Number);
        return;
    }
    if(prev==NULL){
        head = head->next;
    }
    else{
        prev->next = current->next;
    }
    free(current);
}

void display()
{
    struct node *current = head;
    if (current == NULL)
    {
        printf("\nNo List is available.");
    }
    printf("\nNumber:");
    while (current != NULL)
    {
        printf("\t%d", current->number);
        current = current->next;
    }
}

int main()
{
    Delete(18);
    insert(4);
    insert(18);
    Delete(18);
    insert(108);
    display();
}