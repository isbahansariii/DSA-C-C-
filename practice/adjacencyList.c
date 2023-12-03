#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For no of vertex
struct V
{
    int V;
    struct V *next;
};
struct V *head = NULL;

// Multi linked list for storing whole graph
struct vertex
{
    int v; // vertex
    struct vertex *next;
    struct graph *edges;
};
struct vertex *headV = NULL;
struct graph
{
    int source, destination;
    struct graph *next;
};
struct graph *headG = NULL;

void emptyGraph()
{
    if (headV == NULL)
    {
        printf("Graph is empty, i.e. there is no vertex.");
    }
}

void deleteV(int vertex)
{
    struct vertex *prev = NULL;
    struct vertex *current = headV;

    if (headV == NULL)
    {
        emptyGraph();
        return;
    }

    while (current->next != NULL && current->v == vertex)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        headV = headV->next;
        free(current);
        return;
    }
    prev->next = current->next;
    free(current);
}

struct graph *createG(int source, int destination)
{
    struct graph *newedge = (struct graph *)malloc(sizeof(struct graph));
    newedge->source = source;
    newedge->destination = destination;
    newedge->next = NULL;
    return newedge;
}

struct vertex *createV(int source)
{
    // source = vertex
    struct vertex *newnode = (struct vertex *)malloc(sizeof(struct vertex));
    newnode->v = source;
    newnode->edges = NULL;
    newnode->next = NULL;
    return newnode;
}

void insertVertex(int data)
{
    struct V *current = head;
    if (head == NULL)
    {
        struct V *newnode = (struct V *)malloc(sizeof(struct V));
        newnode->V = data;
        newnode->next = NULL;
        current = head = newnode;
        return;
    }
    while(current->next!=NULL && current->V != data){
        current = current->next;
    }
    if(current->V == data){
        // vertex/data is already present
        return;
    }
    if(current->next == NULL){
        struct V *newnode = (struct V *)malloc(sizeof(struct V));
        newnode->V = data;
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }
}

// Insert graph, maintain vertex
void insertG(int source, int destination)
{
    // source is the vertex which is stored in 1st list
    struct vertex *currentV = headV;
    struct graph *currentG = headG;

    // VERTEX MAINTAINANCE

    insertVertex(source);
    insertVertex(destination);

    while (currentV->next != NULL)
    {
        if(currentV->v != source)
            currentV = currentV->next;
    }

    if (headV == NULL)
    {
        headV = currentV = createV(source);
        currentV->edges = headG = currentG = createG(source, destination);
        return;
    }

    else if (currentV->v == source)
    {
        while (currentG->next != NULL)
        {
            currentG = currentG->next;
        }
        // if vertex is build, so we just have to build edge
        currentG->next = createG(source, destination);
        currentG = currentG->next;
        return;
    }
    else if (currentV->next == NULL)
    {
        currentV->next = createV(source);
        currentV = currentV->next;
        currentV->edges = headG = currentG = createG(source, destination);
    }
}

void displayVertex()
{

    // source is the vertex which is stored in 1st list
    struct V *current = head;

    if(head == NULL){
        printf("Graph is empty.");
        return;
    }
    printf("\nVertices: ");
    while (current != NULL)
    {
        printf("\t%d", current->V);
        current = current->next;
    }

}

void main()
{
    insertVertex(4);
    insertVertex(9);
    insertVertex(8);
    // insertG(2,3);
    displayVertex();
//  insertG(3, 1);
}
