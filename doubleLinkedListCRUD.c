#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int value;
    struct node* next;
};

struct node* newNode(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->value = value;
    temp->next = NULL;
    return temp;
}

struct node* insertNode(struct node* head, int value){
    struct node* temp = head;
    if(head == NULL){
        head = newNode(value);
        return head;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode(value);
    temp->next->prev = temp;
    return head;
}

void deleteNode(struct node* head, int value){
    struct node* temp = head;
    while(temp->next->value !=value){
        temp = temp->next;
        if(temp->next == NULL){
            printf("The given value does not exist!!!\n");
            return;
        }
    }
    if(temp->next->next == NULL){
        temp->next = NULL;
        return;
    }
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    //temp->next->prev = temp;
    return;
}

void updateList(struct node* head, int position, int value){
    struct node* temp = head;
    for(int i =1;i<position;i++){
        temp = temp->next;
        if(temp == NULL){
            printf("The given position does not exist!!!\n");
            return;
        }
    }
    temp->value = value;
    return;    
}

void printList(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main(){
    struct node* head = NULL;
        
    for(int i =0;i<10;i++){
        int value;
        scanf("%d",&value);
        head = insertNode(head, value);
    }
    printList(head);
    deleteNode(head, 10);
    printList(head);
    updateList(head, 11, 80);
    printList(head);
    
    return 0;
}