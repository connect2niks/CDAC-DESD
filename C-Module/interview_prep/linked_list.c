#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};

struct node* createNode(int data,struct node *head)
{
	struct node* new = (struct node *)malloc(sizeof(struct node));
	new -> data = data;
	new -> link = head;
	head = new;
	return head;
}

struct node* printList(struct node* head)
{
	struct node* p;
	p = head;
	while(p != NULL)
	{
		printf("%d -> ",p->data);
		p = p->link;
	}
	printf("NULL");
	printf("\n\n");
}

struct node* addend(struct node* head, int data)
{
	struct node* p;
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new -> data = data;
	p = head;
	while(p->link !=NULL)
		p = p->link;
	p->link = new;
	new->link = NULL;
	return head;
}

struct node* InsertAtPos(struct node* head, int data, int pos)
{
	struct node* p;
	p = head;
	for(int i=1; i<pos-1 &&  p!=NULL;i++)
		p = p->link;
	if(p == NULL)
		printf("There are less than %d elements",pos);
	else
	{
		struct node* new = (struct node *)malloc(sizeof(struct node));
		new->data= data;
		if(pos == 1)
		{
			new->link = head;
		       head = new;	
		}
		else
		{
			new->link = p->link;
			p->link = new;
		}
	}
	return head;
}

int main()
{
	int n,pos;
	printf("Enter number of nodes:");
	scanf("%d",&n);
	int data[n];
	printf("Enter data to be inserted:");
	scanf("%d",&data[0]);
	struct node* head = NULL;
	head = createNode(data[0],head);
	for(int i=1; i<n; i++)
	{
		printf("Enter data : ");
		scanf("%d",&data[i]);
		head = addend(head,data[i]);
	}

	printf("Enter data and pos : ");
	scanf("%d%d",&data[0],&pos);
	head = InsertAtPos(head, data[0], pos);
	printList(head);
	return 0;

}
