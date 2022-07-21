/******************************************************************************

 Online C Compiler.
Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
struct node{
int data; //data
struct node *next;//address
}*head;

void createlist(int n);
void display();

int main()
{
int n ,data;
printf("enter the total number of nodes:\n");
scanf("%d",&n);
createlist(n);
printf("data in link\n");
display();
}
void createlist(int n)
{
struct node *newnode,*temp;
int data ,i;
head =(struct node *)malloc(sizeof(struct node));
if(head == NULL)
{
printf("unable to allocte memory\n ");
}
else
{
printf("enter the data of node 1:");
scanf("%d",&data);
head->data = data;
head->next=NULL;
temp=head;
for(i=2;i<=n;i++)
{
newnode = (struct node *)malloc(sizeof(struct node));
if(newnode == NULL)
{
printf("unable to allocte memory\n ");
break;
}
else
{
printf("enter the data of node %d:",i);
scanf("%d",&data);
newnode->data = data;
newnode->next=NULL;
temp->next=newnode;
temp = temp->next;
}

}
printf("linked link created successfully\n");
}
}
void display()
{
struct node *temp;
if(head == NULL)
{
printf("list is empty\n");
}
else
{
temp = head;
while(head!= NULL)
{
printf("data is %d\n",temp->data);
temp = temp->next;
}
}
}
