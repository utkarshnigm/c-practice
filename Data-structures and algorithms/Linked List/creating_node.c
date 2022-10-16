#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")

struct node{
    int data;
    struct node* next;
};

void creatingnode(struct node** head){
    nl;

    struct node* newnode = malloc (sizeof(struct node));
    printf("Enter data for new node: ");
    scanf(" %d",&(newnode->data));
    head = newnode;

nl;
}

void delete(struct node** head){}

int display(struct node** head){
    nl;

    if(*head == NULL) return printf("No first node exist.");
    
    printf("new node data: %d\n", (*head)->data);
    printf("address of new node: %p", (&head));
    nl;

}

int main(){
     
    struct node* head = NULL;
    display(&head);
    creatingnode(&head);
    display(&head);

}