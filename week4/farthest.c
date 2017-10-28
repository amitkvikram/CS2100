/*
   Name: Amit Vikram Singh
   Roll No: 111601001
   Date: 03/10/2017
   Task: farthest.c

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include "queue.h"

struct Graph{
	int **adjWt;
	int V;    	   //V: no of vertices
	char GraphName[100];
};

struct v_Info{
		int dist;
		bool Checked;
		int prev;
		int connected_to_goal;
};

typedef struct Graph Graph;
typedef struct v_Info v_Info;

Graph *CreateGraph(int V){
	Graph *G = (Graph*)malloc(sizeof(Graph));
	G->V = V;
	G->adjWt = (int**)malloc(G->V * sizeof(int*));
	for(int i=0; i<G->V; i++)
		G->adjWt[i] = (int*)calloc(G->V, sizeof(int));
	return G;
}

v_Info* bfsv_Info(Graph *G){
	v_Info *v_InfoPtr;

	v_InfoPtr = (v_Info*)malloc(G->V * sizeof(v_Info));

	v_InfoPtr[0].dist = 0;
	v_InfoPtr[0].Checked = true;
	return v_InfoPtr;
}

//Creating dot file
void MakeDot(Graph *G,v_Info *v_I){
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,G->GraphName);
	strcat(GraphName_cp,".dot");
	printf("Dot File: %s\n",GraphName_cp);
	fp = fopen(GraphName_cp,"w");
	fprintf(fp, "%s%s%s\n", "graph ",G->GraphName,"{");
	for(int i=0; i<G->V-1; i++){
		int flag =0;
		for(int j=i; j<G->V; j++){
			if(G->adjWt[i][j]>0){
				flag =1;
				if(v_I[i].connected_to_goal == 1 && v_I[j].connected_to_goal ==1){
					fprintf(fp, "%s%d -- %d%s","\t",i,j,"[color=red];\n");
				}
				else fprintf(fp, "%s%d -- %d%s","\t",i,j,";\n");
			}
		}
		if(flag == 0) fprintf(fp, "%s%d%s","\t",i,";\n");
	}
	fprintf(fp, "%s%d%s","\t",G->V-1,"\n");
	fprintf(fp, "%s\n", "}");
}


void ShortestPath(v_Info *v_I, int root, int goal, int max){
	printf("Length of Longest shortest path between %d and %d is: %d\n", root, goal, max ); //v_I[goal].dist
	int current = goal;
	printf("longest Shortest Path is: ");

	do{
		printf("%d ",current);
		v_I[current].connected_to_goal = 1;
		current = v_I[current].prev;
	}while(current!= root);

	printf("%d\n",current);
	v_I[current].connected_to_goal = 1;
}

int BreadthFirstSearch(Graph *G){
	v_Info *v_I = bfsv_Info(G);
	int flag = 0;  	//to track if path is found or not
	queue *Q =createQueue();
	int Current;

	v_I[0].Checked =false;
	int i=0;
	int max = 0;
	int diameter_root =0, diameter_goal =0;
	for(int root = 0; root<G->V; root++){
		v_I[root].dist = 0;
		enQueue(&Q, root);
		v_I[root].Checked= true;
		while(!isEmptyQueue(&Q)){
				Current = dequeue(&Q);		//finding current node
					for(int i=0; i<G->V; i++){
						if(G->adjWt[Current][i] > 0){
							if(v_I[i].Checked == false){	//checking if current node has been visited before or not
								v_I[i].Checked = true;	//marking  node as visited
								v_I[i].dist = v_I[Current].dist + G->adjWt[Current][i];	//updating distance from root
								enQueue(&Q, i);
							}
						}

					}
			}
				for(int k = 0; k<G->V; k++){	//updating the diameter @longest shortest path
						v_I[k].Checked = false;
						if(v_I[k].dist>max){	//If distance between two pairs is greater than max distances
							max = v_I[k].dist;
							diameter_root= root;
							diameter_goal = k;
						}
						v_I[k].dist = 0;
				}


		}

 		printf("diameter_root: %d diameter_goal: %d\n",diameter_root, diameter_goal );
		v_I[diameter_root].dist = 0;
		enQueue(&Q, diameter_root);
		while(!isEmptyQueue(&Q)){
			int Current = dequeue(&Q);		//dequeueing current node
			if(Current == diameter_goal) {
				flag = 1;		//returns 1 if Current node is goal means if we have found path from root to goal
				break;
			}
			for(int i=0; i<G->V; i++){
				if(G->adjWt[Current][i] > 0){
					if(v_I[i].Checked == false){	//checking if cerrent node has been visited before or not
						v_I[i].Checked = true;	//marking  node as visited
						v_I[i].dist = v_I[Current].dist + G->adjWt[Current][i];
						v_I[i].prev = Current;
						enQueue(&Q, i);
					}
				}
			}
}


	printf("diameter is: %d %d", diameter_root, diameter_goal);
	ShortestPath(v_I, diameter_root, diameter_goal, max);
	MakeDot(G,v_I);
	return flag;
}

void printAdjacency(Graph *G){

	for(int i=0; i<G->V; i++){
		for(int j=0; j<G->V; j++){
			printf("%d",G->adjWt[i][j]);
		}
		printf("\n");
	}

}



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

	Graph *G = Read(&fp);
	BreadthFirstSearch(G);
	return 0;
}
