#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")

struct node{
    int data;
    struct node* next;
};

struct node* creatingnode(){

    nl;
    struct node* newnode = malloc (sizeof(struct node));
    printf("Enter the data for new node: ");
    scanf(" %d",&(newnode->data));
    nl;
    
    return newnode;    
}

void insertnodeatbeginning(struct node** head){

    struct node* newnode =  (creatingnode());
    newnode->next =  *head;
    *head = newnode;
            
}

void insertnodeatanypos(struct node** head){
    nl;
    printf("Enter the position at which the new node to be inserted: ");
    int n,count=0;
    scanf("%d",&n);
    struct node* newnode = (creatingnode());
    struct node* current = *head;

    while(current != NULL){

        if(count == (n-1)){
            newnode->next = current ->next;
            current->next = newnode;
            break;
        }
        count++;
        current = current->next;
    }
}

void insertnodeatend(struct node** head){
    nl;
    struct node* current = *head;
    struct node* newnode = creatingnode();
    newnode->next = NULL;

    while(current->next != NULL){
        current = current->next;
    }
    current->next = newnode;
}

int display(struct node** head){

    struct node* current = *head;
    if(*head == NULL) return printf("No first node exist.");

    printf("Data in node: ");
    while(current != NULL){
        printf(" %d",current->data);
        current = current->next;
    }

    nl;
}

int main(){
    
    struct node* head = NULL;
    int n;
    
    do {
        nl;
        printf("-----------------------------------------------------"); nl;
        printf("\t\t Menu driven Program"); nl;
        printf("-----------------------------------------------------"); nl; nl;
        printf("1. Inserting node at begining"); nl;
        printf("2. Inserting node at any position"); nl;
        printf("3. Inserting node at ending."); nl;
        printf("-----------------------------------------------------"); nl; nl;
        printf("Enter your choice: ");
        
        int c=0;
        scanf(" %d",&c);

        switch(c){

            case 1: insertnodeatbeginning(&head);
                    display(&head);
                    break;

            case 2: insertnodeatanypos(&head);
                    display(&head);
                    break;
            
            case 3: insertnodeatend(&head);
                    display(&head);
                    break;
            
            default: printf("Wrong choice.");
        }
        n=0;
        nl;
        printf("Wanna continue yes or no? (1/0): ");
        scanf("%d",&n);
    } while(n);

}