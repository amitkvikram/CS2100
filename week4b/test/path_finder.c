/*
   Name: Amit Vikram Singh
   Roll No: 111601001
   Date: 03/10/2017
   Task: path_finder.c
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include "queue.h"

struct Graph{		//Structure to store graph information
	int **adjWt;
	int V;    	   //V: no of vertices
	char GraphName[100];
};

struct v_Info{			//structure to store information about vertices during BFS
		int dist;	//distance of vertex from root
		bool Checked;
		int level;
		int minBlue;	
		int prev;
		int connected_to_goal;
};

typedef struct Graph Graph;
typedef struct v_Info v_Info;

char color[6][20] = {"","red","green","blue"};

Graph *CreateGraph(int V){		//Creating graph data
	Graph *G = (Graph*)malloc(sizeof(Graph));
	G->V = V;
	G->adjWt = (int**)malloc(G->V * sizeof(int*));
	for(int i=0; i<G->V; i++)		//allocating space for adjacency matrix
		G->adjWt[i] = (int*)calloc(G->V, sizeof(int));
	return G;
}

v_Info* bfsv_Info(Graph *G, int root, int goal){
	v_Info *v_InfoPtr;

	v_InfoPtr = (v_Info*)malloc(G->V * sizeof(v_Info));
	
	v_InfoPtr[root].dist = 0;
	v_InfoPtr[root].Checked = true;
	for(int i=0; i<G->V; i++){
	
		v_InfoPtr[i].minBlue =0;
		v_InfoPtr[i].level = 0;
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

//Creating dot file
void MakeDot(Graph *G,v_Info *v_I){	
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,G->GraphName);
	strcat(GraphName_cp,".dot");
	printf("test.dot");
	fp = fopen("test.dot","w");
	fprintf(fp, "%s%s%s\n", "graph ","test","{");
	for(int i=0; i<G->V-1; i++){
		int flag =0;
		for(int j=i; j<G->V; j++){
			if(G->adjWt[i][j]>0){
				flag =1;
				if(v_I[i].connected_to_goal == 1 && v_I[j].connected_to_goal ==1){
					fprintf(fp, "%s%d -- %d%s%s%s","\t",i,j,"[style=dotted color=",color[G->adjWt[j][i]],"];\n");		//coloring path from root to goal
				}
				else fprintf(fp, "%s%d -- %d%s%s%s","\t",i,j,"[color=",color[G->adjWt[j][i]],"];\n");
			}
		}
		if(flag == 0) fprintf(fp, "%s%d%s","\t",i,";\n");
	}
	fprintf(fp, "%s%d%s","\t",G->V-1,"\n");
	fprintf(fp, "%s\n", "}");
}

//Printing Shortest Path
void ShortestPath(v_Info *v_I, int root, int goal, Graph *G){
	printf("Length of shortest path between %d and %d is: %d\n", root, goal, v_I[goal].dist);		//printing length of shortest path between root and goal.
	int current = goal;
	int dist = 0;
	printf("Shortest Path is: ");
	//Printing shortest path between root and goal
	int count =0;
	do{
		if(G->adjWt[current][v_I[current].prev]==3) count++;
		printf("%d ",current);
		v_I[current].connected_to_goal = 1;
		current = v_I[current].prev; 
	}while(current!= root);

	printf("%d\n",current);
	printf("No of blue edges: %d\n",v_I[goal].minBlue); 
	v_I[current].connected_to_goal = 1;	//marking the vertes if it is included in shortest path
}

int BreadthFirstSearch(Graph *G, int root, int goal){
	v_Info *v_I = bfsv_Info(G, root, goal);
	int flag = 0;  	//to track if path is found or not
	queue *Q =createQueue();
	int count = 0;
	int count1 = 0;
	int max =0;
	enQueue(&Q, root);
	v_I[root].prev = root;
	int level = 0;
	while(!isEmptyQueue(&Q)){
		int Current = dequeue(&Q);		//finding current node
		if(Current == goal) {
			flag = 1;		//returns 1 if Current node is equal means if we have found path from root to goal
			break;
		}
		for(int i=0; i<G->V; i++){
			if(G->adjWt[Current][i] >0){
				int inc = 0;
				if(G->adjWt[Current][i] == 3) inc =1;
				if(v_I[i].Checked == false){				
						v_I[i].Checked = true;	//marking  node as visited
						v_I[i].dist = v_I[Current].dist + 1;
						v_I[i].prev = Current;
						v_I[i].minBlue = v_I[Current].minBlue + inc;
						enQueue(&Q, i);
				}
				
				else if(v_I[Current].minBlue + inc < v_I[i].minBlue){
					v_I[i].Checked = true;	//marking  node as visited
					v_I[i].dist = v_I[Current].dist + 1;
					v_I[i].minBlue = v_I[Current].minBlue + inc;
					v_I[i].prev = Current;
				}
			}
		}
	}

	ShortestPath(v_I, root, goal, G);
	MakeDot(G,v_I);
	return flag;
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
	printf("Enter Filename");
	scanf("%s", FileName);
	
	FILE *fp;
	fp=fopen(FileName, "r");	//Opening .txt file
	
	 
	 if(fp==0)	//Checking for file error in opening
	 {
	  	printf("Error in opening the file %s.\n", FileName);
	  	return(1);
	 }
	
	Graph *G = Read(&fp);
	int root, goal;		//Aim is to search if path between root and goal exists
	printf("Enter x and y: ");
	scanf("%d%d", &root, &goal);
	int flag = BreadthFirstSearch(G, root, goal);
	if(flag == 1) printf("Connected\n");
	else printf("Not Connected\n");
	return 0;
}
