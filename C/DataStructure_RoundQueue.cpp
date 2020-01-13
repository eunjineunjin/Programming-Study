/*
Radix Sort �������
with Round Queue 
*/

#include <stdio.h>
#define MAXSIZE 10

//Round Queue
typedef struct Queue{
	int arr[MAXSIZE];
	int front;	//front���� ������ ���� 
	int rear;	//rear-1���� ������ ���� 
}Queue;

void Init(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

int isFull(Queue* q)
{
	return (q->rear+1)%MAXSIZE == q->front;	//Full�̸� 1 return 	
}

void Push(Queue* q, int item)
{
	if(isFull(q))
	{
		printf("ť�� ���� á���ϴ�.");
	}
	else
	{
		q->arr[q->rear] = item;
		q->rear = (q->rear+1)%MAXSIZE;
	}
}

int isEmpty(Queue* q)
{
	return (q->front)==(q->rear);	//Empty�� 1 return 
}

int Pop(Queue* q)
{
	if(isEmpty(q))
	{
		printf("ť�� ������ϴ�.");
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
