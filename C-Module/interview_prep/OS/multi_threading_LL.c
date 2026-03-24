#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t lock;

 // LL structure
typedef struct node
{
	int data;
	struct node *link;
}node;

node *head = NULL;

void insert(int v)
{
	pthread_mutex_lock(&lock);
	node *new = malloc(sizeof(node));
	new->data = v;
	new->link = head;
	head = new;	
	pthread_mutex_unlock(&lock);

}

void print_list()
{
	pthread_mutex_lock(&lock);
	node *temp = head;
	printf("List: ");
	while(temp)
	{
		printf("%d->",temp->data);
		temp = temp->link;
	}
	printf("\n");
	pthread_mutex_unlock(&lock);
}

void *thread_fun(void *arg)
{	
	int id = *(int *)arg;
	for(int i=0; i<5; i++)
		insert(id*10+i);
}

int main()
{
	int id[] ={1,2,3};
	pthread_t thread[3];
	pthread_mutex_init(&lock,NULL);

	// Thread Create
	for(int i=0; i<3; i++)
	pthread_create(&thread[i],NULL,thread_fun,&id[i]);


	// Thread join
	for(int i=0; i<3; i++)
	pthread_join(thread[i],NULL);

	print_list();

	pthread_mutex_destroy(&lock);

	return 0;
}
