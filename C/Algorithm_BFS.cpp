/*
BFS
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define QueueSIZE 20

/////Making Graph/////
typedef struct node{
	char name;
	node* next;
}node;

typedef struct Graph{
	node* arr[MAXSIZE];
	int Vnum;	//Vertex number
	int visited[MAXSIZE];	//for BFS
}Graph;

void Init(Graph* G)
{
	G->Vnum = 0;
}

node* NewVertex(Graph* G, char node_name)
{
	node* NewVertex = (node*)malloc(sizeof(node));
	NewVertex->name = node_name;
	NewVertex->next = NULL;
	
	G->arr[G->Vnum] = NewVertex;
	++(G->Vnum);
	
	return NewVertex;
}

void NewEdge(node* A, node* B)	//Undirected
{
	//A link
	node* NewEdge1 = (node*)malloc(sizeof(node));
	NewEdge1->name = B->name;
	NewEdge1->next = NULL;
	
	node* tmp = A;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NewEdge1;
	
	//B link
	node* NewEdge2 = (node*)malloc(sizeof(node));
	NewEdge2->name = A->name;
	NewEdge2->next = NULL;
	
	tmp = B;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NewEdge2;
}

void ShowGraph(Graph* G)
{
	for(int i=0; i<G->Vnum; i++)
	{
		printf("[%c]", G->arr[i]->name);
		
		node* tmp = G->arr[i]->next;
		while(tmp)
		{
			printf("\t->%c", tmp->name);
			tmp = tmp->next;
		}
		printf("\n");
	}
	printf("\n");
}
//////////////////////

/////Queue For BFS/////
typedef struct Queue{
	int arr[QueueSIZE];
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
	return (q->rear+1)%QueueSIZE == q->front;	//Full이면 1 return 	
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
		q->rear = (q->rear+1)%QueueSIZE;
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
		q->front = (q->front+1)%QueueSIZE;
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
			i = (i+1)%QueueSIZE;	
		}
	}
}
///////////////////////

void BFS(Graph* G)
{
	Queue Q;
	Init(&Q);
	//Initialize
	char spn = -1;	//starting point name
	printf("Enter a starting point: ");
	scanf("%c", &spn);
	int spi = NULL;	//starting point index
	for(int i=0; i<G->Vnum; i++)
	{
		G->visited[i] = 0;
		if(spn == G->arr[i]->name)
		{
			spi = i;
			G->visited[i] = 1;
			Push(&Q, i);
		}
	}
	
	while(!isEmpty(&Q))
	{
		
		int now = Pop(&Q);
		node* tmp = G->arr[now];
		printf("%c ", tmp->name);
		while (tmp->next)
		{
			//Finding index in Graph
			for(int i=0; i=G->Vnum; i++)
			{
				if(tmp->next->name == G->arr[i]->name)
				{
					if(G->visited[i]!=0)
					{
						G->visited[i] = G->visited[now]+1;
						Push(&Q, i);
					}
				}
			}
		}
	}
	/*
	for(int i=0; i<G->Vnum; i++)
	{
		printf("[%c] ", G->arr[i]->name);
		printf("%d", G->visited[i]);
		printf("\n");
	}*/
}



int main()
{
	Graph G;
	Init(&G);
	
	//Making vertex
	node* r = NewVertex(&G, 'r');
	node* s = NewVertex(&G, 's');
	node* t = NewVertex(&G, 't');
	node* u = NewVertex(&G, 'u');
	node* v = NewVertex(&G, 'v');
	node* w = NewVertex(&G, 'w');
	node* x = NewVertex(&G, 'x');
	node* y = NewVertex(&G, 'y');
	
	//Making Edge(Undirected)
	NewEdge(r, v);
	NewEdge(r, s);
	NewEdge(s, w);
	NewEdge(w, t);
	NewEdge(w, x);
	NewEdge(t, x);
	NewEdge(t, u);
	NewEdge(u, x);
	NewEdge(u, y);
	NewEdge(x, y);
	
	//Print
	ShowGraph(&G);
	BFS(&G);
}
