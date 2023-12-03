// BFS

#include<stdio.h>
#include<stdlib.h>

// defines a struct named as queue
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};
 
// Checks if the queue is empty by comparing the front and rear pointers
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
// Checks if the queue is full by comparing the rear pointer to the queue's size minus one.
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

// Adds an element to the queue from the front of the queue
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        // increment the rare pointer
        q->r++;
        q->arr[q->r] = val;
    }
}

// Remove and return an element from the front of the queue
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        // increment the front pointer
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    // Initializing Queue (Array Implementation)
    struct queue q;
    q->size = 400;
    q->f = q.r = 0;

    q->arr = (int*) malloc(q.size*sizeof(int));
    
    // BFS Implementation 
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};

    int a [8][8] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,1},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,1,0},
        {0,1,0,1,0,1,1}, 
        {0,0,0,0,1,0,0} 
    };

    printf("%d", i);

    visited[i] = 1;

    // Enqueue i for exploration
    enqueue(&q, i);
    
    while ( !isEmpty(&q) )
    {
        // dequeues nodes mark visited
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0){
                printf(" %d", j);
                visited[j] = 1;

                // check neighbors if they haven't been visited yet.
                enqueue(&q, j);
            }
        }
    }
    return 0;
}