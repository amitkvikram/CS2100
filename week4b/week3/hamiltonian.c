#include<stdio.h>
#include<stdlib.h>
#include "double_linked_list.h"
#include "CircularLinkedList.h"
#include "queue.h"

struct Graph{       //Structure to store graph information
    int **adjWt;
    int V;         //V: no of vertices
    char GraphName[100];
    int isolated;
    int components;
};

struct v_Info{          //structure to store information about vertices during BFS
        int dist;   //distance of vertex from root
        bool Checked;   
        int prev;
};

typedef struct Graph Graph;
typedef struct v_Info v_Info;


Graph *CreateGraph(int V){      //Creating graph data
    Graph *G = (Graph*)malloc(sizeof(Graph));
    G->V = V;
    G->adjWt = (int**)malloc(G->V * sizeof(int*));
    for(int i=0; i<G->V; i++)       //allocating space for adjacency matrix
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
    return v_InfoPtr;
}

int allVisited(Graph *G, v_Info *v_I){
	for(int i = 0; i<G->V; i++){
		if(!v_I[i].checked) return false;
	}
	
	return true;
}

int isSafe(Graph *G, v_Info *v_I, int vertex, int strtNode){
	int flag = 0;
	for(int i=0; i<G->V; i++){
		if(i!=strtNode && i!=vertex){
			if(v_I[i].checked = false && G->adjWt[i][vertex]>0){
				return 1;
			}
		}
	}
	
	if(v_I[strtNode][vertex] >0 && allVisited(G, v_I)){
		return 1;
	}
	
	return 0;
}

bool hamiltonian(Graph *G, v_Info *v_I, int vertex, queue **Q){
	if(!isSafe(G, v_I, vertex, 0){	//checking if it's safe to add vertex means atleast one unvisited vertex is attached to it.
		return false;
	}
	
	if(v_I[strtNode][vertex] >0 && allVisited(G, v_I)){	//if cycle is completed
			enQueue(&Q, vertex);
			return true;
	}		
	
	v_I[vertex].checked = true;
	int i = 0;
	
	for(i = 1; i<G->V; i++){		
		if(G->adjwt[vertex][i]> 0 && i!= vertex && hamiltonian(G, v_I, i, Q)){
			enQueue(&Q, vertex);
			count++;
			return true;
		}		
	}
		
	if(i == G->V){
		v_I[vertex].checked = false;
		return false;
	}
	
	return true;
}		

int main(){
    char FileName[50];
    printf("Enter Filename: ");
    scanf("%s", FileName);
    
    FILE *fp;
    fp=fopen(FileName, "r");    //Opening .txt file
    
     
     if(fp==0)  //Checking for file error in opening
     {
        printf("Error in opening the file %s.\n", FileName);
        return(1);
     }
    
    Graph *G = Read(&fp);
    fclose(fp);
    v_Info *v_I = bfsv_Info(G, 0, 0);
    queue *Q = createQueue();
    hamiltonian(G, v_I, 0, &Q);
}


