#include <stdio.h>
#include <stdlib.h>

#define max 15

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

int main(){
    struct node* head = NULL;
    struct node* attacher = NULL;
    int count = rand()%max;
    int attachElement = (rand()%count)+1;
    for(int i = 1;i<=count;i++){
        head = insertNode(head, i);
    }
    struct node*temp = head;
    for(int i = 1;i<count;i++){
        if(i ==attachElement){
            attacher = temp;
        }
        temp = temp->next;
    }
    temp->next = attacher;
    struct node* temp1 = head;
    // for(int i = 1;i<2*max;i++){
    //     printf("%d ",temp1->value);
    //     temp1= temp1->next;
    // }
    
    int address[count+1];
    for(int i =0;i<=count;i++){
        address[i] = temp1;
        temp1 = temp1->next;
        //printf("%d ", address[i]);
    }
    for(int i =0;i<count;i++){
        if(address[count] == address[i]){
            printf("%d is the loping point.\n", i+1);
            break;
        }
    }
    return 0;
}