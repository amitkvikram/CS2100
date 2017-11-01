/*
   Name: Amit Vikram Singh
   Roll No: 111601001
   Date: 10/10/2017
   Task: eulerian.c
   Running Programme: enter "make" command in terminal, and output(object) file eulerian.o will be created.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include "heap.h"

struct Graph{		//Structure to store graph information
	int **adjWt;
	int V;    	   //V: no of vertices
	char GraphName[100];
	int isolated;
	int components;
};

struct v_Info{			//structure to store information about vertices during BFS
		int dist;	//distance of vertex from root
		bool Checked;
		int prev;
};

typedef struct Graph Graph;
typedef struct v_Info v_Info;

Graph *CreateGraph(int V){		//Creating graph data
	Graph *G = (Graph*)malloc(sizeof(Graph));
	G->V = V;
	G->adjWt = (int**)malloc(G->V * sizeof(int*));
	for(int i=0; i<G->V; i++)		//allocating space for adjacency matrix
		G->adjWt[i] = (int*)calloc(G->V, sizeof(int));

	G->components = 0;
	G->isolated = 0;

	return G;
}

v_Info* bfsv_Info(Graph *G, int root, int goal){
	v_Info *v_InfoPtr;

	v_InfoPtr = (v_Info*)malloc(G->V * sizeof(v_Info));

  for(int i = 0; i<G->V; i++){
    v_InfoPtr[i].dist = INT_MAX;
  }
	v_InfoPtr[root].dist = 0;
	v_InfoPtr[root].Checked = true;
	return v_InfoPtr;
}

//Creating dot file
void MakeDot(Graph *G,v_Info *v_I, int strtNode, int pathLength, Node **Headptr){
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,G->GraphName);
	strcat(GraphName_cp,"new.dot");
	printf("Output: %s\n",GraphName_cp);
	fp = fopen(GraphName_cp,"w");
	fprintf(fp, "%s%s%s\n", "digraph ",G->GraphName,"{");
	int temp = strtNode;
	for(int i=1; i<pathLength+1; i++){
		int current = ValueAtGivenPosition(Headptr,i);
		fprintf(fp, "%s%d -> %d%s","\t",temp,current,"[color=red];\n");	//coloring path which was traced  in BFS
		temp = current;
	}
	fprintf(fp, "%s%d%s","\t",G->V-1,"\n");
	fprintf(fp, "%s\n", "}");
}


//Printing adjacency matrix
void printAdjacency(Graph *G){

	for(int i=0; i<G->V; i++){
		for(int j=0; j<G->V; j++){
			printf("%d ",G->adjWt[i][j]);
		}
		printf("\n");
	}

}

//Reading Graph file
Graph* Read(FILE **fp){
	char GraphName[50] ;
	fscanf(*fp, " %[^\n]s", GraphName);	//reading graph name
	char GraphType[50];
	fscanf(*fp, " %[^\n]s", GraphType);	//reding graph type
	int num_vertices;
	fscanf(*fp, "%d", &num_vertices);	//scannig number of vertices in the graph
	Graph* G = CreateGraph(num_vertices);
  queue *Q = createQueue();

	for(int i=0;i<G->V; i++){	//reading adjacecy matrix
		for(int j=0;j<G->V;j++){
			fscanf(*fp, "%1d", &G->adjWt[i][j]);
      enQueue(&Q, G->adjWt[i][j])
		}
	}

	strcpy(G->GraphName,GraphName);

	printAdjacency(G);
	return G;
}

//main begins here
int main(){
	char FileName[50];
	printf("Enter Filename: ");
	scanf("%s", FileName);

	FILE *fp;
	fp=fopen(FileName, "r");	//Opening .txt file


	 if(fp==0)	//Checking for file error in opening
	 {
	  	printf("Error in opening the file %s.\n", FileName);
	  	return(1);
	 }
	Graph *G = Read(&fp);
	fclose(fp);
	v_Info *v_I = bfsv_Info(G, 0, 0);
	if(!isEulerian(G, v_I)) {
		printf("status: Eulerian Circuit doesn't exist\n");
		return 0;
	}
	else printf("status: Eulerian Circuit Exist\n");

	int strtNode;
	printf("Enter starting node: ");
	scanf("%d", &strtNode);
	PrintEulerian(G, v_I, strtNode);
	return 0;

}
//main ends here
