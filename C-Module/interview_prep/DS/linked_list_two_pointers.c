/*
 * slow and fast pointers/tortoise and hare
 * startingloop()
 * findloop
 * createlist()
 * revlist()
 * findmid()
 * printlist()
 * delbegin()
 * makeloop()
  */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *createlist(int data, node *head){
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->link = NULL;
    if(head==NULL)
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
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

node *delbegin(node* head){
    printf("Deleting node from beginning\n");
    if(head == NULL)
    return NULL;
    
    node* temp = head;
    head = head->link;
    free(temp);
    return head;
}

bool findloop(node *head){
    node *slow, *fast;
    slow = fast = head;
    while(fast!=NULL && fast->link != NULL){
        slow = slow->link;
        fast = fast->link->link;
        if(slow == fast)
        return true;
    }
    return false;
}

void makeloop(node *head){
    node *slow, *fast;
    slow = fast = head;
    while(fast!=NULL && fast->link!=NULL){
        slow = slow->link;
        fast = fast->link->link;
    }
    fast->link = slow;
}

int findmid(node *head){
    printf("Find mid of LinkedList\n");
    node *slow, *fast;
    slow = fast = head;
    while(fast!=NULL && fast->link!=NULL){
        slow = slow->link;
        fast = fast->link->link;
    }
    return slow->data;
}

node *startingloop(node *head){
    node *slow, *fast;
    slow = fast = head;
    while(fast != NULL && fast->link != NULL){
        slow = slow->link;
        fast = fast->link->link;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow = slow->link;
                fast = fast->link;
            }
                return slow;
        }
    }
    return NULL;
}

node *revLL(node *head){
    node *prev, *cur, *next;
    prev = NULL;
    cur = head;
    while(cur!=NULL){
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

int main(){
    // creating list
    node *head = NULL;
    for(int i=0; i<10; i++){
        head = createlist(i+1, head);
    }
    //printing list
    printlist(head);
    //delete from beginning
    // head = delbegin(head);
    // printlist(head);
    //find mid of list
    // int mid = findmid(head);
    // printf("Mid element of LL is %d.\n",mid);
    
    // make a loop in LL
   // makeloop(head);
    
    //find loop
    // if(findloop(head))
    // printf("Loop in LL\n");
    // else
    // printf("Linear LL\n");
    // node *temp = startingloop(head);
    // if(temp!=NULL)
    // printf("starting of the loop - %d\n",temp->data);
    // else printf("There is no loop in LL\n");
    head = revLL(head);
    printlist(head);   
    return 0;
}
