/*
 * slow and fast pointers/tortoise and hare
 * createlist()
 * revlist()
 * findmid()
 * printlist()
  */


#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *findmid(node *head){
    node *slow,*fast;
    slow = head;
    fast = head;
    while(fast!=NULL && fast->link!=NULL){
        slow = slow->link;
        fast = fast->link->link;
    }
    return slow;
}

node *revlist(node *head){
    node *prev,*next,*temp;
    prev = NULL;
    temp = head;
    
    while(temp!=NULL){
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

node *createlist(int data, node *head){
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->link = NULL;
    
    if(head == NULL)
    return new;
    
    node *temp  = head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = new;
    
    return head;
}

void printlist(node *head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
int main(){
    
    int data[6]={1,2,3,4,5,6};
    
    node *head = NULL;
    for(int i=0; i<6; i++){
        head = createlist(data[i], head);
    }
    
    printlist(head);
    
    head = revlist(head);
    
    printlist(head);
    
    node *mid = findmid(head);
    printf("Middle Node: %d \n",mid->data);
    
    return 0;
}
