// Adjacency list
// Indegree Outdegree

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

using namespace std;

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100  

// Define a structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Define a structure for the graph, containing an array of adjacency lists and the number of vertices
struct Graph {
    struct Node* adjList[MAX_VERTICES];
    int numVertices;
};

// Function to create a new graph with the specified number of vertices
struct Graph* createGraph(int numVertices) {

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add a new vertex to the graph
void addVertex(struct Graph* graph) {
    if (graph->numVertices < MAX_VERTICES) {
        graph->numVertices++;
        graph->adjList[graph->numVertices - 1] = NULL;
    }
}

// Function to delete a vertex from the graph
void deleteVertex(struct Graph* graph, int vertex) {
    if (vertex >= 0 && vertex < graph->numVertices) {
        struct Node* current = graph->adjList[vertex];
        graph->adjList[vertex] = NULL;

        for (int i = 0; i < graph->numVertices; i++) {
            struct Node* prev = NULL;
            current = graph->adjList[i];

            while (current != NULL) {
                if (current->vertex == vertex) {  
                    if (prev != NULL) {
                        prev->next = current->next;
                    } else {
                        graph->adjList[i] = current->next;
                    }
                    free(current);  // Free the memory of the deleted edge
                    break;
                }
                prev = current;
                current = current->next;
            }
        }
    }
}

// Function to add an edge between two vertices
void addEdge(struct Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
        newNode->vertex = dest;
        newNode->next = graph->adjList[src];  
        graph->adjList[src] = newNode;
    }
}

// Function to delete an edge between two vertices
void deleteEdge(struct Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        struct Node* current = graph->adjList[src];
        struct Node* prev = NULL;

        while (current != NULL) {
            // Find and delete the edge between the specified vertices
            if (current->vertex == dest) { 
                if (prev != NULL) {
                    prev->next = current->next;
                } else {
                    graph->adjList[src] = current->next;
                }
                free(current);
                break;
            }
            prev = current;
            current = current->next;
        }
    }
}

// Function to search for a vertex in the graph
int searchVertex(struct Graph* graph, int vertex) {
    return (vertex >= 0 && vertex < graph->numVertices);
}

// Function to calculate the indegree of a vertex
int inDegree(struct Graph* graph, int vertex) {
    int indegree = 0;
    if (vertex >= 0 && vertex < graph->numVertices) {
        for (int i = 0; i < graph->numVertices; i++) {
            struct Node* current = graph->adjList[i];
            while (current != NULL) {
                if (current->vertex == vertex) {
                    indegree++;
                }
                current = current->next;
            }
        }
    }
    return indegree;
}

// Function to calculate the outdegree of a vertex
int outDegree(struct Graph* graph, int vertex) {
    int outdegree = 0;
    if (vertex >= 0 && vertex < graph->numVertices) {
        struct Node* current = graph->adjList[vertex];
        while (current != NULL) {
            outdegree++;
            current = current->next;
        }
    }
    return outdegree;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("\tAdjacency list of vertex %d: ", i);
        struct Node* current = graph->adjList[i];
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5);  // Create a graph with 5 vertices

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    cout << "\n Initial Graph:" << endl;
    printGraph(graph);

    //deleteEdge(graph, 0, 1);
    deleteEdge(graph, 1, 3);
    deleteVertex(graph, 2);

    cout << "\n\nGraph after edge and vertex deletion:" << endl;  
    printGraph(graph);

    cout << "\nIndegree of vertex 0: " << inDegree(graph, 0) << endl;  
    cout << "Outdegree of vertex 0: " << outDegree(graph, 0) << endl; 

    cout << "Is vertex 4 in the graph? " << (searchVertex(graph, 4) ? "Yes" : "No") << endl;  // Search for a vertex

    return 0;
}
