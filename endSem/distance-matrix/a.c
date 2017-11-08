/*
   End-Sem Examination
   Name: Amit Vikram Singh
   Roll No: 111601001
   Date: 07/11/2017
   Task: distance-matrix
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include "queue.h"

struct Graph{		//Structure to store graph information
	int **adjWt;
	int **arr;
	int V;    	   //V: no of vertices
	char GraphName[100];
	int components;
};

struct v_Info{			//structure to store information about vertices during BFS
		int dist;	//distance of vertex from root
		bool Checked;
		int prev;
		int connected_to_goal;
};

typedef struct Graph Graph;
typedef struct v_Info v_Info;

Graph *CreateGraph(int V){		//Creating graph data
	Graph *G = (Graph*)malloc(sizeof(Graph));
	G->V = V;
	G->adjWt = (int**)malloc(G->V * sizeof(int*));
	for(int i=0; i<G->V; i++)		//allocating space for adjacency matrix
		G->adjWt[i] = (int*)calloc(G->V, sizeof(int));
		
		
	G->arr = (int**)malloc(G->V * sizeof(int*));
	for(int i=0; i<G->V; i++)		//allocating space for adjacency matrix
		G->arr[i] = (int*)calloc(G->V, sizeof(int));
	for(int i = 0; i<G->V; i++){
		for(int j = 0; j<G->V; j++){
			if(j!= i) G->arr[i][j] = -1;
		}
	}
		
	G->components = 0;
		
	return G;
}

v_Info* bfsv_Info(Graph *G){
	v_Info *v_InfoPtr;

	v_InfoPtr = (v_Info*)malloc(G->V * sizeof(v_Info));
	for(int i = 0; i<G->V; i++){
		v_InfoPtr[i].dist = -1;
	}
	return v_InfoPtr;
}

void freeGraph(Graph *G, v_Info *v_I){
	free(v_I);
	for(int i=0; i<G->V; i++){
		free(G->adjWt[i]);
	}

	free(G->adjWt);
	free(G);
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

//Creating .txt file
void MakeTxt(Graph *G,v_Info *v_I, float avgDist, int num){
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,G->GraphName);
	strcat(GraphName_cp,"-distance.txt");
	printf("Output File: %s\n",GraphName_cp);
	fp = fopen(GraphName_cp,"w");
	fprintf(fp, "%s%s\n", "graph ",G->GraphName);
	if(G->components == 1){
		fprintf(fp, "Average Distance: %f\n",avgDist/num);
	}
	for(int i=0; i<G->V-1; i++){
		for(int j=0; j<G->V; j++){
					fprintf(fp, "%d ",G->arr[i][j]);		//coloring path from root to goal
		}
		fprintf(fp, "\n");
	}
}

// Printing Shortest path ____ called from the function ShortestPath
void PrintShortesPath(v_Info *v_I, int current, int root){
	if(current == root){
		v_I[current].connected_to_goal = 1;
		return ;
	}
	v_I[current].connected_to_goal = 1;
	current = v_I[current].prev;
	PrintShortesPath(v_I, current, root);
	printf("%d ",current);
	return ;
}

//Printing Shortest Path
void ShortestPath(v_Info *v_I, int root, int goal){
	printf("Length of shortest path between %d and %d is: %d\n", root, goal, v_I[goal].dist);		//printing length of shortest path between root and goal.
	int current = goal;
	printf("Shortest Path is: ");
	// Printing shortest path between root and goal
	PrintShortesPath(v_I, current, root);
	printf("%d ",goal );
	printf("\n");
}

void Set(Graph *G, v_Info *v_I, int root, int goal){
	for(int i =0; i<G->V; i++){
		v_I[i].dist = -1;
	}
	for(int i = 0; i<G->V; i++){
		v_I[i].Checked = false;
	}
	v_I[root].dist = 0;
	v_I[root].Checked = true;
}

int BreadthFirstSearch(Graph *G, v_Info *v_I, int root, int goal){
	int flag = 0;  	//to track if path is found or not
	queue *Q =createQueue();
	enQueue(&Q, root);
	while(!isEmptyQueue(&Q)){
		int Current = dequeue(&Q);		//finding current node
		if(Current == goal) {
			flag = 1;		//returns 1 if Current node is goal means if we have found path from root to goal
			break;
		}
		for(int i=0; i<G->V; i++){
			if(G->adjWt[Current][i] > 0){
				if(v_I[i].Checked == false){	//checking if cerrent node has been visted before or not
					v_I[i].Checked = true;	//marking  node as visited
					v_I[i].dist = v_I[Current].dist + G->adjWt[Current][i];	//updting distance from root
					v_I[i].prev = Current;	//setting parent of ith node
					enQueue(&Q, i);
				}
			}
		}
	}
	free(Q);
	return v_I[goal].dist;	
}

//Printing adjacency matrix
void printAdjacency(Graph *G){

	for(int i=0; i<G->V; i++){
		for(int j=0; j<G->V; j++){
			printf("%d",G->adjWt[i][j]);
		}
		printf("\n");
	}

}

//Reading Graph file
Graph* Read(FILE **fp){
	char GraphName[50] ;
	fscanf(*fp, " %[^\n]s", GraphName);
	char GraphType[50];
	fscanf(*fp, " %[^\n]s", GraphType);
	int num_vertices;
	fscanf(*fp, "%d", &num_vertices);	//scannig number of vertices in the graph
	Graph* G = CreateGraph(num_vertices);

	for(int i=0;i<G->V; i++){
		for(int j=0;j<G->V;j++){
			fscanf(*fp, "%1d", &G->adjWt[i][j]);
		}
	}

	strcpy(G->GraphName,GraphName);

	printAdjacency(G);
	return G;
}

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

	printf("Algorithm: BFS\n");
	Graph *G = Read(&fp);
	v_Info *v_I = bfsv_Info(G);
	Components(G, v_I);
	int root, goal, distance;
	for(int i = 0; i<G->V; i++){
		for(int j= i+1; j<G->V; j++){
			Set(G, v_I, i, j);
			root = i; goal =j;
			distance = BreadthFirstSearch(G, v_I, root, goal);  //Breadth First Search
			G->arr[i][j] = distance;
			G->arr[j][i] = distance;
		}
	}
	
	float avgDist = 0;
	int num =0;
	//If graph is connected calculating average Distance
	if(G->components == 1){
		for(int i =0; i<G->V; i++){
			for(int j = i+1; j<G->V; j++){
					num++;
					avgDist += G->arr[i][j];
			}
		}
		printf("Average Distance: %f\n", avgDist/num);   //printting average distance
	}
	MakeTxt(G,v_I, avgDist, num);
        freeGraph(G, v_I);
	return 0;
}


























