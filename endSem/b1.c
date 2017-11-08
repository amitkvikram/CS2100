/*
   End-Sem Examination
   Name: Amit Vikram Singh
   Roll No: 111601001
   Date: 07/11/2017
   Task: Distance-2Coloring
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
	int **arr;
	char GraphName[100];
	int isolated;
	int components;
};

struct v_Info{			//structure to store information about vertices during BFS
		int dist;	//distance of vertex from root
		bool Checked;	
		int prev;
		int color;
};

typedef struct Graph Graph;
typedef struct v_Info v_Info;

char color[13][20] = {"red","blue","green","brown","yellow", "black","gold", "chocolate","cyan4","azure2","firebrick1","gold3","darkorange4"};

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
	G->isolated = 0;
	
	return G;
}

v_Info* bfsv_Info(Graph *G, int root, int goal){
	v_Info *v_InfoPtr;

	v_InfoPtr = (v_Info*)malloc(G->V * sizeof(v_Info));
	
	v_InfoPtr[root].dist = 0;
	v_InfoPtr[root].Checked = true;
	for(int i=0; i<G->V; i++)		//allocating space for adjacency matrix
		v_InfoPtr[i].color = -1;
	return v_InfoPtr;
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
				if(v_I[i].Checked == false){	//checking if cerrent node has been visted before or not;
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

void calcDist(Graph *G, v_Info *v_I){
	int root, goal, distance;
	for(int i = 0; i<G->V; i++){
		for(int j= i+1; j<G->V; j++){
			Set(G, v_I, i, j);
			root = i; goal =j;
			distance = BreadthFirstSearch(G, v_I, root, goal);
			G->arr[i][j] = distance;
			G->arr[j][i] = distance;
		}
	}
	

}

//Creating dot file
void MakeDot(Graph *G,v_Info *v_I){	
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,G->GraphName);
	strcat(GraphName_cp,"1.dot");
	printf("%s\n",GraphName_cp);
	fp = fopen(GraphName_cp,"w");
	fprintf(fp, "%s%s%s\n", "graph ",G->GraphName,"{");
	for(int i=0; i<G->V-1; i++){
		int flag =0;
		for(int j=i; j<G->V; j++){
			if(G->adjWt[i][j]>0){
				flag =1;
					fprintf(fp, "%s%d -- %d%s","\t",i,j,";\n");		//coloring path from root to goal
			}
		}
		if(flag == 0) fprintf(fp, "%s%d%s","\t",i,";\n");
	}
	fprintf(fp, "%s%d%s","\t",G->V-1,"\n");
	for(int i=0; i<G->V; i++){
		fprintf(fp, "%s%d%s%s%s%s","\t",i,"[color=",color[v_I[i].color],", style=filled]",";\n");		//coloring path from root to goal
	}
	fprintf(fp, "%s\n", "}");
}



int checkColoring(Graph *G, v_Info *V, int i, int j){
	for(int k = 0; k<G->V ; k++){
	//printf("i: k: %d %d ",i, k);
		if(G->adjWt[i][k]>0){
			if(V[k].color == j && k!=i) return 0;
		}
		
		else if(G->arr[i][k]<3){
			if(V[k].color == j && k!=i) return 0;
		}
	}

	return 1;
}

void Color(Graph *G, v_Info *v_I){
        int root = 0;
        v_I[root].color = 0;
        for(int i =0; i<G->V;i++){
        	v_I[i].Checked =false;
        }
        v_I[root].Checked = true;
        int flag = 0;  	//to track if path is found or not
	queue *Q =createQueue();
	enQueue(&Q, root);
	int n =0;
	while(!isEmptyQueue(&Q)){
		int Current = dequeue(&Q);		//finding current node
		for(int i =0; i<G->V; i++){
			if(G->adjWt[Current][i]>0){
				if(v_I[i].Checked == false){	//checking if cerrent node has been visted before or not
					v_I[i].Checked = true;
					for(int j=0; j<13; j++){
						if(checkColoring(G, v_I, i,j)){
							v_I[i].color = j;
							enQueue(&Q, i);
							break;
						}
					}
				}
			}
		}
		
	}
	free(Q); 
	MakeDot(G,v_I);

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
	calcDist(G, v_I);   //function to calculate shortest path between each pair
	Color(G,v_I);
	return 0;

}
//main ends here
