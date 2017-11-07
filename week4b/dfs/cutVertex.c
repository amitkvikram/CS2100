#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>
#include "stack.h"

struct Graph{		//Structure to store graph information
	int **adjWt;
	int V;    	   //V: no of vertices
	char GraphName[100];
};

struct v_Info{			//structure to store information about vertices during BFS
		int dist;	//distance of vertex from root
		bool Checked;
		int prev;
		int connected_to_goal;
    int low;
    int disc_time;
    int children;
    bool cut_vertex;
};

typedef struct Graph Graph;
typedef struct v_Info v_Info;

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
  for(int i = 0; i<G->V; i++){
    v_InfoPtr[i].dist = 0;
  	v_InfoPtr[i].Checked = false;
    v_InfoPtr[i].low = INT_MIN;
    v_InfoPtr[i].disc_time = 0;
    v_InfoPtr[i].children = 0;
    v_InfoPtr[i].cut_vertex = false;
  }
  v_InfoPtr[root].prev = -1;
	return v_InfoPtr;
}

void freeGraph(Graph **G, v_Info **v_I){
  for(int i=0; i<(*G)->V; i++){
		free((*G)->adjWt[i]);
	}
	free((*G)->adjWt);
	free(*v_I);
	free(*G);
}

//Creating dot file
void MakeDot(Graph *G,v_Info *v_I){
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,G->GraphName);
	strcat(GraphName_cp,".dot");
	printf("Output File: %s\n",GraphName_cp);
	fp = fopen(GraphName_cp,"w");
	fprintf(fp, "%s%s%s\n", "graph ",G->GraphName,"{");
	for(int i=0; i<G->V-1; i++){
		int flag =0;
		for(int j=i; j<G->V; j++){
			if(G->adjWt[i][j]>0){
				flag =1;
				if(v_I[j].connected_to_goal == 1 && (i == v_I[j].prev || j == v_I[i].prev) && v_I[i].connected_to_goal == 1){
					fprintf(fp, "%s%d -- %d%s","\t",i,j,"[color=red];\n");		//coloring path from root to goal
				}
				else fprintf(fp, "%s%d -- %d%s","\t",i,j,";\n");
			}
		}
		if(flag == 0) fprintf(fp, "%s%d%s","\t",i,";\n");
	}
	fprintf(fp, "%s%d%s","\t",G->V-1,"\n");
	fprintf(fp, "%s\n", "}");
  fclose(fp);
}

int min(int a, int b){
  if(a<b) return a;
  else return b;
}

void cutVertex(Graph *G, v_Info *v_I, int root){
  // stack *Top;
  for(int i = 0; i<G->V; i++){
      if(i==root && v_I[i].children > 1){
        v_I[i].cut_vertex = true;
      }

      else{
        for(int j =0; j<G->V; j++){
            if(v_I[i].low >= v_I[i].disc_time && G->adjWt[i][j]>0){
              v_I[i].cut_vertex = true;
          }
       }
     }
  }

  for(int i =0; i<G->V; i++){
      printf("i: %d cut_vertex: %d disc_time: %d low: %d\n", i, (int)v_I[i].cut_vertex, v_I[i].disc_time, v_I[i].low);
  }
}

void printPath(Graph *G, v_Info *v_I){
  for(int i = 0; i<G->V; i++){
    printf("i: %d, i_prev: %d\n",i, v_I[i].prev);
  }
}

void dfsRecursive(Graph *G, v_Info *v_I, int root, int time){
  if(v_I[root].Checked == false){
    printf("%d ",root);
    v_I[root].Checked = true;
    v_I[root].connected_to_goal =1;
     v_I[root].disc_time = time++;
     v_I[root].low = time;
    for(int i = 0; i < G->V; i++){
      if(G->adjWt[root][i]> 0){
        if(v_I[i].Checked == false){
          v_I[i].prev =root;
          v_I[root].children ++;
          dfsRecursive(G, v_I, i, time);
          v_I[root].low = min(v_I[i].low, v_I[root].low);
        }

        else if(v_I[root].prev != i){
          v_I[root].low = min(v_I[root].low, v_I[i].disc_time);
        }
      }

    }
  }
}

void dfsIterative(Graph *G, v_Info *v_I, int  root){
  stack *Top = NULL;
  stackPush(&Top, root);
  while(!isEmpty(&Top)){
    int current = stackPop(&Top);
    if(v_I[current].Checked == false){
      v_I[current].Checked = true;
      v_I[current].connected_to_goal =1;
      printf("i: %d ",current);
      // int index = -1;
      for(int i = 0; i<G->V; i++){
          if(G->adjWt[current][i]>0 && v_I[i].Checked == false){
            stackPush(&Top, i);
              v_I[i].prev = current;
          }
      }

    }
  }
}

void printAdjacency(Graph *G){

	for(int i=0; i<G->V; i++){
		printf("%d: ",i);
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

	printf("Algorithm: DFS\n");
	Graph *G = Read(&fp);
  fclose(fp);
	int root;		//Aim is to search if path between root and goal exists
	printf("Enter Root: ");
	scanf("%d", &root);
  v_Info *v_I = bfsv_Info(G, root, 0);
	//dfsIterative(G, v_I, root);
  dfsRecursive(G, v_I, root, 0);
  printf("\n");
  printPath(G, v_I);
  cutVertex(G, v_I, root);
  MakeDot(G, v_I);
  freeGraph(&G, &v_I);
	return 0;
}
