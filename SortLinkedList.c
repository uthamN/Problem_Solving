#include <stdio.h>
#include <stdlib.h>

#define n 10
#define nl printf("\n");

struct node{
    int value;
    struct node* next;
};

struct node* newNode(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
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
    return head;
}

void printList(struct node* head){
    struct node* temp = head;
    if(temp){
        printf("%d  ",temp->value);
        printList(temp->next);
    }
    return;
}

struct node* sortJoin(struct node* ll1, struct node* ll2){
    struct node* temp = ll1;
    struct node* temp1 = ll1->next;
    struct node* temp2 = ll2;
    while(temp1 && temp2){
        if(temp1->value < temp2->value){
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }else{
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
    }
    if(temp1){
        while(temp1){
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
    }else{
        while(temp2){
            temp->next = temp2;
            temp2 = temp2->next;   
            temp = temp->next;
        }
    }
    return ll1;
}

int main(){
    struct node* ll1 = NULL;
    struct node* ll2  = NULL;
    int t=0;
    
    int l1 = (rand()%n) + 1;
    int l2 = (rand()%n) + 1;
    
    for(int i =0;i<l1;i++){
        t+= rand()%n;
        ll1 = insertNode(ll1, t);
    }
    t = 0;
    for(int i =0;i<l1;i++){
        t+= rand()%n;
        ll2 = insertNode(ll2, t);
    }
    printList(ll1);
    nl
    printList(ll2);
    nl
    int k = (ll1->value <= ll2->value) ? 1 : 0;
    
    if(k){
        ll1 = sortJoin(ll1, ll2);
        printList(ll1);

    }else{
        ll2 = sortJoin(ll2, ll1);
        printList(ll2);
    }
    
    return 0;
}