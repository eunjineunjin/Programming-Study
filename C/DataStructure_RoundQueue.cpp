/*
Round Queue
with C language
only for integer, based on array
*/
#include <stdio.h>
#define MAXSIZE 10

typedef struct Queue{
	int arr[MAXSIZE];
	int front;	//front부터 데이터 존재 
	int rear;	//rear-1까지 데이터 존재 
}Queue;

void Init(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

int isFull(Queue* q)
{
	return (q->rear+1)%MAXSIZE == q->front;	//Full이면 1 return 	
}

void Push(Queue* q, int item)
{
	if(isFull(q))
	{
		printf("큐가 가득 찼습니다.");
	}
	else
	{
		q->arr[q->rear] = item;
		q->rear = (q->rear+1)%MAXSIZE;
	}
}

int isEmpty(Queue* q)
{
	return (q->front)==(q->rear);	//Empty면 1 return 
}

int Pop(Queue* q)
{
	if(isEmpty(q))
	{
		printf("큐가 비었습니다.");
	}
	else
	{
		int item = q->arr[q->front];
		q->front = (q->front+1)%MAXSIZE;
		return item;
	}
}

void Show(Queue* q)
{	
	int i = q->front;
	while(1)
	{
		if(i == q->rear)
		{
			break;
		}
		else
		{
			printf("%d ", q->arr[i]);
			i = (i+1)%MAXSIZE;	
		}
	}
}

int main()
{
	Queue Q;
	Init(&Q);
	Push(&Q, 1);
	Push(&Q, 2);
	Push(&Q, 3);
	Pop(&Q);
	
	Show(&Q);
}
