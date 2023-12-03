#include<stdio.h>
#include<stdlib.h>
#define max 5

struct Node{
    int data;
    struct Edge *next;
};

struct Edge{
    struct Node* toVertex;
    struct Edge *next;
};
struct Edge *Ehead = NULL;
struct Edge *Etail = NULL;
struct Node *arr[max];

struct Node* Vertice(){

    int key; 
    printf("Enter the data in the Vertices : ");
    scanf("%d",&key);

    struct Node* newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}

void Edges(){

    int source,destination;
    printf("Enter the Edge (0 to %d) in node (0 to %d) : ",max,max);
    scanf("%d %d",&destination,&source); 
    for(int i = 0 ; i < max ; i++){
        if(arr[i]->data == source){ // finds the source node from the Pointer Array..
            for(int j = 0 ; j < max ; j++){
                if(arr[j]->data == destination){ // finds the destination node from the Pointer Array..
                    struct Edge* newNode;
                    newNode = (struct Edge*) malloc(sizeof(struct Edge));
                    newNode->toVertex = arr[j];
                    newNode->next = NULL;

                    if(arr[i]->next == NULL){
                        arr[i]->next= Ehead = Etail = newNode;
                    }
                    else{
                        Etail->next = newNode;
                        Etail = newNode;
                    }
                }
            }
        }
    }
}

void Display(){
    for(int i = 0 ; i < max ; i++){
        printf("%d-->",arr[i]->data);
        struct Edge* Hold;
        Hold = arr[i]->next;
        while(Hold!=NULL){
            printf("%d-->",Hold->toVertex->data);
            Hold= Hold->next;
        } 
        printf("\n");    
    }
}

int main(){

    for(int i = 0; i < max ; i++){
       arr[i] =  Vertice();
    }
    Edges();
    Edges();
    Edges();
    Edges();
    Edges();
    Edges();
    Display();
    return 0;
}