// Queue using linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue
{
    int data;
    struct queue *link;
};
struct queue *front = NULL;
struct queue *rare = NULL;

void enqueue(int data)
{
    struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->data = data;
    newnode->link = NULL;

    if (front==NULL && rare==NULL)
    {
        front = rare = newnode;
        return;
    }
    rare->link = newnode;
    rare = newnode;
}

void dequeue(){
    struct queue *temp = front;
    if(front==NULL && rare==NULL){
        printf("\nUnderflow Alert! Queue is empty.");
        return;
    }
    printf("\nDequeueing %d from queue.", front->data);
    front = front->link;
    free(temp);
}

void display()
{
    struct queue *current = front;
    if (front == NULL && rare==NULL)
    {
        printf("\nUnderflow Alert! Queue is empty.");
        return;
    }
    printf("\nDisplay:");
    while (current != NULL)
    {
        printf("\t%d", current->data);
        current = current->link;
    }
}

void peekRare(){
    if(front==NULL && rare==NULL){
        printf("\nUnderflow Alert! Queue is empty.");
        return;
    }
    printf("\nRare element (Last inserted element) of queue is: %d", rare->data);
}

void peekFront(){
    if(front==NULL && rare==NULL){
        printf("\nUnderflow Alert! Queue is empty.");
        return;
    }
    printf("\nFront element (First inserted elemet) of queue is: %d", front->data);
}

void main(){
    display();
    enqueue(4);
    enqueue(8);
    enqueue(10);
    display();
    peekFront();
    peekRare();
    dequeue();
    dequeue();
    enqueue(80);
    enqueue(12);
    enqueue(9);
    enqueue(0);
    display();
    peekFront();
    peekRare();
}
