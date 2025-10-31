#include <stdio.h>
#include <stdbool.h>
typedef struct circular_buffer
{
	int arr[10];
	int head;
	int tail;
}cir_buf;

void cb_init(cir_buf *cb)
{
	cb->head = 0;
	cb->tail = 0;
}

bool cb_push(cir_buf* buff, int val)
{
	if((buff->head+1)%10 == buff->tail)
	{
		printf("Buffer is full\n");
		return false;
	}

	buff->arr[buff->head] = val;
	buff->head = (buff->head + 1)%10;
	return true;
}

bool cb_pop(cir_buf* buff, int* val)
{
	if(buff->head == buff->tail)
	{
		printf("buffer is empty\n");
		return false;
	}

	*val = buff->arr[buff->tail];
	buff->tail = (buff->tail +1)%10;
	return true;

}
int main()
{
	cir_buf cb;
	cb_init(&cb);

	for(int i=0; i<7; i++)
	cb_push(&cb, i+1);
	int val;
	//for(int i=0; i<3; i++)
	if(cb_pop(&cb,&val))
		printf("Popped: %d\n",val);

//	while(cir_buf->head!=cir_buf->tail){
//		printf("DATA - %d",cir_buf->arr[cir_buf->head]);
//		cir_buf->head = (cir_buf->head+1)%10;
//	}

	while(cb_pop(&cb,&val))
	{
		printf("%d, ",val);
	}
	printf("\n");
}

