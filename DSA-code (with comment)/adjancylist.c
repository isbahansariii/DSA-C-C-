// Adjacency list
// Indegree Outdegree

#include <stdio.h>  // Include the standard input/output library for C-style I/O
#include <stdlib.h>  // Include the standard library for memory allocation functions
#include <iostream>  // Include the C++ I/O stream library
using namespace std;  // Use the standard C++ namespace

#define MAX_VERTICES 100  // Define the maximum number of vertices in the graph

// Define a structure for a node in the adjacency list
struct Node {
    int vertex;  // Store the vertex value
    struct Node* next;  // Pointer to the next node in the adjacency list
};

// Define a structure for the graph, containing an array of adjacency lists and the number of vertices
struct Graph {
    struct Node* adjList[MAX_VERTICES];  // Array of adjacency lists
    int numVertices;  // Number of vertices in the graph
};

// Function to create a new graph with the specified number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));  // Allocate memory for the graph
    graph->numVertices = numVertices;  // Set the number of vertices

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;  // Initialize each adjacency list to NULL
    }

    return graph;
}

// Function to add a new vertex to the graph
void addVertex(struct Graph* graph) {
    if (graph->numVertices < MAX_VERTICES) {
        graph->numVertices++;  // Increase the number of vertices
        graph->adjList[graph->numVertices - 1] = NULL;  // Initialize the new adjacency list to NULL
    }
}

// Function to delete a vertex from the graph
void deleteVertex(struct Graph* graph, int vertex) {
    if (vertex >= 0 && vertex < graph->numVertices) {
        struct Node* current = graph->adjList[vertex];  // Get the adjacency list for the specified vertex
        graph->adjList[vertex] = NULL;  // Set the adjacency list to NULL

        for (int i = 0; i < graph->numVertices; i++) {
            struct Node* prev = NULL;
            current = graph->adjList[i];

            while (current != NULL) {
                if (current->vertex == vertex) {  // Find and delete the edges connected to the specified vertex
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
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for a new edge
        newNode->vertex = dest;
        newNode->next = graph->adjList[src];  // Add the edge to the adjacency list of the source vertex
        graph->adjList[src] = newNode;
    }
}

// Function to delete an edge between two vertices
void deleteEdge(struct Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        struct Node* current = graph->adjList[src];
        struct Node* prev = NULL;

        while (current != NULL) {
            if (current->vertex == dest) {  // Find and delete the edge between the specified vertices
                if (prev != NULL) {
                    prev->next = current->next;
                } else {
                    graph->adjList[src] = current->next;
                }
                free(current);  // Free the memory of the deleted edge
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

    addEdge(graph, 0, 1);  // Add edges between vertices
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    cout << "\n Initial Graph:" << endl;  // Print the initial graph
    printGraph(graph);

    //deleteEdge(graph, 0, 1);
    deleteEdge(graph, 1, 3);
    deleteVertex(graph, 2);  // Delete edges and a vertex

    cout << "\n\nGraph after edge and vertex deletion:" << endl;  // Print the graph after deletion
    printGraph(graph);

    cout << "\nIndegree of vertex 0: " << inDegree(graph, 0) << endl;  // Calculate and print indegree
    cout << "Outdegree of vertex 0: " << outDegree(graph, 0) << endl;  // Calculate and print outdegree

    cout << "Is vertex 4 in the graph? " << (searchVertex(graph, 4) ? "Yes" : "No") << endl;  // Search for a vertex

    return 0;  // Return 0 to indicate successful program execution
}
