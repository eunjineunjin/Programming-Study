#include <stdio.h>
#define MAXSIZE 10

typedef struct Stack{
	int arr[MAXSIZE];
	int top = -1;
}Stack;

int isFull(Stack*s)
{
	return s->top == 30;	//Full이면 1 return 
}

void Push(Stack* s, int item)
{
	if(isFull(s))
	{
		printf("스택이 가득 찼습니다.");
	}
	else
	{
		s->top++;
		s->arr[s->top] = item;
	}
}

int isEmpty(Stack *s)
{
	return s->top == -1;	//Empty면 1 return 
}

int Pop(Stack *s)
{
	if(isEmpty(s))
	{
		printf("스택이 비었습니다.");
	}
	else
	{
		int item = s->arr[s->top];
		s->top--;
		return item;
	}
}

int Peek(Stack *s)
{
	if(isEmpty(s))
	{
		printf("스택이 비었습니다.");
	}
	else
	{

		return s->arr[s->top];
	}
}

void Show(Stack *s)
{
	for(int i=(s->top); i>-1; i--)
	{
		printf("|%d|\n", s->arr[i]);
	}
	printf("---");
}

int main()
{
	Stack S;
	Push(&S, 1);
	Push(&S, 2);
	Push(&S, 3);
	Pop(&S);
	
	Show(&S);
}
