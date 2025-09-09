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

void sortlist(struct node *head)
{
	struct node *i;
	struct node *j;
	int temp;
	for(i=head; i->link!=NULL; i=i->link)
	{
		for(j=i->link; j!=NULL; j=j->link)
		{
			if(i->data > j->data)
			{
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

void count(struct node * head)
{
	struct node *p;
	int count=0;
	p=head;
	while(p!= NULL)
	{
		p=p->link;
		count++;
	}
	printf("Number of elements in linked list : %d\n ",count);
}

void search(struct node * head, int item)
{
	struct node *p = head;
	int pos = 1;
	while(p!=NULL)
	{
		if(p->data == item)
		{
			printf("item = %d found on pos = %d\n",item,pos);
			return;
		}
	pos++;
	p=p->link;
	}
	printf("item %d is not found\n",item);
}

struct node *addafter(struct node *head,int data,int item)
{
	struct node *p;
	p = head;
	while(p!=NULL)
	{
		if(p->data == item)
		{
			struct node *new = (struct node *)malloc(sizeof(struct node));
			new->data = data;
			new->link = p->link;
			p->link = new;
			return head;
		}
		p = p->link;
	}
	printf("%d not present in list\n",item);
	return head;
}

struct node *addbefore(struct node *head,int data,int item)
{
	struct node *p;
	if(head == NULL)
	{
		printf("List is empty \n");
		return head;
	}

	if(item == head->data)
	{
		struct node *new = (struct node *)malloc(sizeof(struct node));
                new->data = data;
		new->link = head;
		head = new;
		return head;
	}
	p = head;
	while(p!=NULL)
	{
		if(p->link->data == item)
		{
			struct node *new = (struct node *)malloc(sizeof(struct node));
			new->data = data;
			new->link = p->link;
			p->link = new;
			return head;
		}
		p = p->link;
	}
	printf("%d not present in the list\n",item);
	return head;
}

struct node *del(struct node *head,int data)
{

}

struct node *reverse(struct node *head)
{

}


int main()
{
	int n,pos,item;
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
	sortlist(head);
	printList(head);
	count(head);
	printf("Enter the item you find\n");
	scanf("%d",&item);
	search(head,item);
	return 0;

}
