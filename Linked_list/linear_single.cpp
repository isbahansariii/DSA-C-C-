#include <stdio.h>
#include <stdlib.h>

struct course
{
    int number;
    struct course *next;
};
struct course*head = NULL;

void insert(int Number)
{
    struct course *newnode = (struct course *)malloc(sizeof(struct course));
    struct course *current = head;
    newnode->number = Number;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = current = newnode;
        return;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
    current = newnode;
}

void Delete(int Number){

    struct course *prev = NULL;
    struct course *current = head;

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
    // struct course *current = (struct course*)malloc(sizeof(struct course));
    struct course *current = head;
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