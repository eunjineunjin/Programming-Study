#include <stdio.h>
#define MAXSIZE 10

typedef struct Queue{
	int arr[MAXSIZE];
	int front = 0;	//front부터 데이터 존재 
	int rear = 0;	//rear-1까지 데이터 존재 
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
	return q->rear == (MAXSIZE+1);	//Full이면 1 return 
}

void Push(Queue* q, int item)
{
	if(isFull(q))
	{
		int choice;
		printf("큐가 가득 찼습니다.\n큐를 앞으로 당길까요?\n");
		printf("1.예	2.아니오\n");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				Pull(q);
				break;
			case 2:
				break;
			default:
				printf("선택할 수 없는 값입니다.");
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
