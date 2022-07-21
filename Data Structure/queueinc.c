/******************************************************************************

 Online C Compiler.
Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
void enqueue();
void dequeue();
void display();
int front =-1,rear =-1;
int arr[MAX];

int main()
{
int choice;
while(choice != 4)
{
printf("1)insert an element into queue\n2)delete element from queue \n 3)Display\n4)exit\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
break;
default:
printf("choose valid choice\n");
}
}
}
void enqueue()
{
int item;
printf("enter element\n");
scanf("%d",&item);
if (rear == MAX -1)
{
printf("queue is overflow\n");
return;
}
else if (front ==-1 && rear ==-1)
{
front =0;
rear =0;
}
else
{
rear =rear+1;
}
arr[rear]=item;
}
void dequeue()
{
int item;
if (front == -1 && rear == -1)
{
printf("queue underflow\n");
return;
}
else
{
item=arr[front];
if(front == rear)
{
front = -1;
rear = -1;
}
else
{
front=front+1;
}
}
printf("deleted element %d\n",item);
}
void display()
{
int i;
if (rear == -1)
{
printf("empty queue\n");
}
else
{
printf("queue elements\n");
for(i = front;i<=rear;i++)
{
printf("%d \t",arr[i]);
}
}
}
