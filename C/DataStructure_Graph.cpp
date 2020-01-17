/*
Graph
Adgacency-list representation
Directed
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char name;
	int weight;
	node* next;
}node;

node* NewVertex(char node_name)
{
	node* NewVertex = (node*)malloc(sizeof(node));
	NewVertex->name = node_name;
	NewVertex->weight = NULL;
	NewVertex->next = NULL;
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

void ShowGraph(node* root)
{
	printf("[%c]", root->name);
	
	node* tmp = root->next;
	while(tmp)
	{
		printf("\t-%d->", tmp->weight);
		printf("%c", tmp->name);
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	//Making vertex
	node* A = NewVertex('A');
	node* B = NewVertex('B');
	node* C = NewVertex('C');
	node* D = NewVertex('D');
	
	//Making Edge(Directed)
	NewEdge(A, D, 5);
	NewEdge(B, A, 10);
	NewEdge(B, C, 15);
	NewEdge(B, D, 20);
	NewEdge(D, A, 5);
	NewEdge(D, C, 10);
	
	//Show
	ShowGraph(A);
	ShowGraph(B);
	ShowGraph(C);
	ShowGraph(D);
}



