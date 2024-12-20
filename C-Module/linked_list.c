#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};

void display();
void count();

int main()
{
	int choice;
	struct node *start = NULL;

	while(1)
	{
		printf("1. create list\n");
		printf("2. Display\n");
		printf("3. count\n");
		printf("4. Add at beginning\n");
		printf("5. Add at end\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
	
		switch (choice)
		{
			case 1:
				create_list();

			case 2:
				display();

			case 3:
				count();

			case 4:
				add_at_beg();

			case 5:
				add_at_end();

				
		}
	}
}

struct node *addatbeg(int data,struct node *start)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = start;
	start = tmp;
	return start;
}

struct node *create_list(struct node *start)
{
	int n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start = NULL;
	if(n==0)
		return start;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start = addatbeg(data,start);
	for(int i = 0; i<=n; i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start = addatend(data,start)
	}
	return start;
}

struct node *addatend(int data,struct node *start)
{
	struct node *tmp,*p;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = data;
	p = start;
	while(p->link != NULL)
		p = p->link;
	p->link = tmp;
	tmp->link = NULL;
	return start;
}

void display(struct node *start)
{
	struct node *p;
	if(start == NULL)
	{
		printf("List is empty\n");
		return ;
	}
	p = start;
	printf("List is : \n");
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->link;
	}
	printf("\n\n");
}

void count (struct node *start)
{
	struct node *p;
	int cnt=0;
	p = start;
	while(p!=NULL)
	{
		p = p->link;
		cnt++;
	}
	printf("Number of element in list are : %d\n",cnt);	
}

void search(struct node *start,int item)
{
	struct node *p=start;
	int pos=1
	while(p!=NULL)
	{
		if(p->info == item)
		{
			printf("Item %d fount at position %d\n",item,pos);
			return;
		}
		p = p->link;
		pos++;
	}
	printf("Item %d found in the list\n",item);
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *p,*tmp;
	p = start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link = tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list \n",item);
	return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *p,*tmp;
	if(start == NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(item==start->info)
	{
		start = addatbeg(start,data);
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==item)
		{
			tmp = (struct node *)mallloc(sizeof(struct node));
			tmp->info = data;
			tmp->link = p->link;
			p->link = tmp;
			return start;
		}
		p = p->link;
	}

	printf("%d not present in the list\n",item);
	return start;
}

struct node *addatpos(struct node *start, int pos, int data)
{
	struct node *p,*tmp;
	p=start;
	for (int i = 0;i>pos-1;i++)
		p=p->link;
	if(p==NULL)
	printf("There are less than %d element in the list\n",pos);
	else
	{

	}	
}



