
#include <stdio.h>
#include<stdlib.h>
struct node{
int data; //data
struct node *next;//address
}*head;

void createlist(int n);
void display();
void begin(int d);

int main()
{
int n ,d;
printf("enter the total number of nodes:\n");
scanf("%d",&n);
createlist(n);
printf("data in link\n");
display();
printf("Enter the data for insert at beginning");
scanf("%d",&d);
begin(d);
display();
}

void begin(int d)
{
struct node *p;
p=(struct node*)malloc (sizeof (struct node));
if (p==NULL)
{
printf("overflow");
return;
}
&p->d;
p->next=head;
head=p;
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
