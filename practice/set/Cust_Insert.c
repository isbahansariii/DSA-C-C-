// Coustimization Insert

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};
struct node *set1 = NULL;
struct node *set2 = NULL;

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
void InsertSpecific(int data, int index){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->number = data;
	temp->next = NULL;
	
	struct node* curr2 = set2;
	int size = 0;
	while(curr2 != NULL){
		if(size == index){
			temp->next = curr2->next;
			curr2->next = temp;
			break;
		}
		size++;
		curr2 = curr2->next;
	}
}

void CustomInsert(int value, int element){
	struct node* curr1 = set1;
	while(curr1 != NULL){   // copied list1 into list2
		set2 = insert(set2, curr1->number);
		curr1 = curr1->next;
	}
	
	struct node* curr2 = set2;
	int index = 0;
	while(curr2 != NULL){ // inserting new node after every occurence of certain number
		if(curr2->number == value){
			InsertSpecific(element,index);
		}
		index++;
		curr2 = curr2->next;
	}
}

void sort_list3()
{
    struct node *curr = set2; // Initialize a pointer to the start of list3
    struct node *nextNode;

    int swapped, temp;

    // Perform the Bubble Sort algorithm
    do
    {
        swapped = 0;
        curr = set2;

        while (curr->next != NULL)
        {
            nextNode = curr->next;

            // Compare adjacent elements and swap them if they are in the wrong order
            if (curr->number > nextNode->number)
            {
                temp = curr->number;
                curr->number = nextNode->number;
                nextNode->number = temp;
                swapped = 1; // Flag to indicate that a swap occurred
            }
            curr = curr->next; // Move to the next element in list3
        }
    } while (swapped); // Continue sorting until no more swaps are needed
}

int main()
{
    set1 = insert(set1, 2);
    set1 = insert(set1, 4);
    set1 = insert(set1, 3);
    set1 = insert(set1, 2);
    set1 = insert(set1, 8);
    set1 = insert(set1, 2);
    set1 = insert(set1, 5);
    set1 = insert(set1, 1);
    set1 = insert(set1, 2);

    printf("Set: ");
    display(set1);

    printf("\nCoustumization: ");
	CustomInsert(2,10);
    display(set2);
}