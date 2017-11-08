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
#include "queue.h"
#include "CircularLinkedList.h"
#include "stack.h"

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
		int edges; //no of edges attached to a vertex
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

	v_InfoPtr[root].dist = 0;
	v_InfoPtr[root].Checked = true;
	for(int i=0;i<G->V; i++){	//reading adjacecy matrix
		for(int j=0;j<G->V;j++){
			if(G->adjWt[i][j]>0) v_InfoPtr[i].edges = 0;
		}
	}

	for(int i=0;i<G->V; i++){	//reading adjacecy matrix
		for(int j=0;j<G->V;j++){
			if(G->adjWt[i][j]>0) v_InfoPtr[i].edges++;
		}
	}
	return v_InfoPtr;
}

//Checking if all vertices have even degree
bool isEvenDegree(Graph *G){
	int degree =0;
	for(int i=0; i<G->V; i++){
		degree = 0;
		for(int j=0; j<G->V; j++){
			if(G->adjWt[i][j]>0) degree++;
		}
		if(degree%2!=0) return false;	//checking for element with odd degree
	}
	return true;
}

//Counting number of isolated vertices
void Isolated(Graph *G, v_Info *v_I){
	for(int i = 0; i<G->V; i++){
		int n=0;
		for(int j = 0; j<G->V; j++){
		 	if(G->adjWt[i][j] == 0) n++;
		}
		if(n == G->V) G->isolated++;	//checking for isolated vertex and incrementing no of isolated vertex
	}
}

//Counting Number of connected components
void Components(Graph *G, v_Info *v_I){
	queue *Q = createQueue();
	for(int root = 0; root<G->V; root++){
		if(v_I[root].Checked == false){
			G->components++;
			enQueue(&Q, root);
			while(!isEmptyQueue(&Q)){
			int Current = dequeue(&Q);		//finding current node
				for(int i=0; i<G->V; i++){
					if(G->adjWt[Current][i] > 0){
						if(v_I[i].Checked == false){	//checking if cerrent node has been visted before or not
							v_I[i].Checked = true;	//marking  node as visited
							v_I[i].dist = v_I[Current].dist + G->adjWt[Current][i];
							v_I[i].prev = Current;
							enQueue(&Q, i);

						}
					}
				}
			}
		}
	}
	free(Q);
	for(int i=0; i<G->V; i++){
				v_I[i].Checked = false;
	}
}

//Checking if eulerian circuit exists or not
bool isEulerian(Graph *G, v_Info *v_I){
	Components(G, v_I);
	Isolated(G, v_I);
	printf("No of connected components: %d\n",G->components);
	printf("No of isolated vertices: %d\n",G->isolated);
	if(G->components - G->isolated >1) return false;	//this condition implies there are two are more connected components
	if(!isEvenDegree(G)) return false;			//If element with odd degree is present then return false
	return true;
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

void PushEulerian(Graph *G, v_Info *v_I, int strtNode, Node **Head, int *pathLength,int index){
	int CurrentNode = strtNode;
	do{
		for(int i = 0; i<G->V; i++){
			if(G->adjWt[CurrentNode][i] > 0){
				// printf("CurrentNode: %d i: %d\n",CurrentNode, i);
				*pathLength = *pathLength +1;
				G->adjWt[CurrentNode][i] = 0;
				G->adjWt[i][CurrentNode] = 0;
				CurrentNode = i;
				InsertAtGivenPosition(Head, CurrentNode, index);
				if(index!=-1) index++;
				Printlist(Head);
				v_I[i].edges--;
				v_I[CurrentNode].edges--;
				v_I[i].Checked = true;
				break;
			}
		}
	}while(CurrentNode!=strtNode);
	// Printlist(Head);
	for(int i = 0; i<G->V; i++){
		if(v_I[i].Checked == true){
			for(int j = 0; j<v_I[i].edges/2; j++){
				int index1 = search(Head, i);
				PushEulerian(G, v_I,  i, Head, pathLength, index1);
			}
		}
	}
}

//finding and printing eulerian path
void PrintEulerian(Graph *G, v_Info *v_I, int strtNode){
	Node *Head = NULL;   //Circular Linked List
  int pathLength = 0;

	int CurrentNode = strtNode;
	insert(&Head, CurrentNode);
	v_I[CurrentNode].Checked = true;
	PushEulerian(G, v_I, CurrentNode, &Head, &pathLength,-1);
	printf("pathLength: %d\n", pathLength);
	MakeDot(G, v_I, strtNode, pathLength, &Head);
	printf("Eulerian Circuit is: ");
	Printlist(&Head);
	printf("\n");
	printAdjacency(G);
	FreeMemory(&Head);
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

	for(int i=0;i<G->V; i++){	//reading adjacecy matrix
		for(int j=0;j<G->V;j++){
			fscanf(*fp, "%1d", &G->adjWt[i][j]);
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
