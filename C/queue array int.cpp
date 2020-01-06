#include <stdio.h>
#define MAXSIZE 10

typedef struct Queue{
	int arr[MAXSIZE];
	int front = 0;	//front���� ������ ���� 
	int rear = 0;	//rear-1���� ������ ���� 
}Queue;

void Pull(Queue* q)
{
	int interval = q->front;
	
	for(int i=q->front; i<q->rear; i++)
	{
		q->arr[i-interval] = q->arr[i];
	}
}

int isFull(Queue* q)
{
	return q->rear == (MAXSIZE+1);	//Full�̸� 1 return 
}

void Push(Queue* q, int item)
{
	if(isFull(q))
	{
		int choice;
		printf("ť�� ���� á���ϴ�.\nť�� ������ �����?\n");
		printf("1.��	2.�ƴϿ�\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				Pull(q);
				break;
			case 2:
				break;
			default:
				printf("������ �� ���� ���Դϴ�.");
		}
		
	}
	else
	{
		q->arr[q->rear] = item;
		q->rear++;
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
		q->front++;
		return item;
	}
}

void Show(Queue* q)
{
	for(int i=q->front; i<q->rear; i++)
	{
		printf("|%d", q->arr[i]);
	}
}

int main()
{
	Queue Q;
	Push(&Q, 1);
	Push(&Q, 2);
	Push(&Q, 3);
	Pop(&Q);
	
	Show(&Q);
} 
