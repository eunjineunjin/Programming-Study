/*
Radix Sort �������
with Round Queue 
*/

#include <stdio.h>
#include <math.h>
#define MAXSIZE 10	//Queue Size

/////Round Queue/////
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
/////////////////////


///////Radix Sort/////MSB->LSB
void RadixSort(int* arr, int size, int MSD)
{
	Queue Q[10];
	for(int i=0; i<10; i++)
	{
		Init(&Q[i]);
	}
	
	for(int i=0; i<MSD; i++)
	{
		for(int j=0; j<size; j++)
		{
			int value = int(arr[j]/pow(10, MSD-i-1))%10;	//pow(10, i) if MSB<-LSB
			Push(&Q[value], arr[j]);
		}
		for(int k=0; k<10; k++)
		{
			int index = 0;
			while(!isEmpty(&Q[k]))
			{
				arr[index] = Pop(&Q[k]);
				index++;
			}
		}
	}
}



int main()
{
	int arr_size = 8;	//length of array
	int MSD = 3;	//Most Signficant Digit
	int arr[arr_size] = {326, 453, 608, 835, 751, 435, 704, 690};
	
	RadixSort(arr, arr_size, MSD);
	
	//Print
	for(int i=0; i<arr_size; i++)
	{
		printf("%d ", arr[i]);
	}
}
