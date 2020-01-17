/*
Graph
Adgacency-list representation
Directed
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct node{
	char name;
	int weight;
	node* next;
}node;

typedef struct Graph{
	node* arr[MAXSIZE];
	int Vnum;	//Vertex number
}Graph;

void Init(Graph* G)
{
	G->Vnum = 0;
}

node* NewVertex(Graph* G, char node_name)
{
	node* NewVertex = (node*)malloc(sizeof(node));
	NewVertex->name = node_name;
	NewVertex->weight = NULL;
	NewVertex->next = NULL;
	
	G->arr[G->Vnum] = NewVertex;
	++(G->Vnum);
	
	return NewVertex;
}

void NewEdge(node* root, node* connected, int weight)	//Directed
{
	node* NewConnected = (node*)malloc(sizeof(node));
	NewConnected->name = connected->name;
	NewConnected->weight = weight;
	NewConnected->next = NULL;
	
	node* tmp = root;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NewConnected;
}

void ShowGraph(Graph* G)
{
	for(int i=0; i<G->Vnum; i++)
	{
		printf("[%c]", G->arr[i]->name);
		
		node* tmp = G->arr[i]->next;
		while(tmp)
		{
			printf("\t-%d->", tmp->weight);
			printf("%c", tmp->name);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

int main()
{
	Graph G;
	Init(&G);
	
	//Making vertex
	node* A = NewVertex(&G, 'A');
	node* B = NewVertex(&G, 'B');
	node* C = NewVertex(&G, 'C');
	node* D = NewVertex(&G, 'D');
	
	//Making Edge(Directed)
	NewEdge(A, D, 5);
	NewEdge(B, A, 10);
	NewEdge(B, C, 15);
	NewEdge(B, D, 20);
	NewEdge(D, A, 5);
	NewEdge(D, C, 10);
	
	//Print
	ShowGraph(&G);
}



