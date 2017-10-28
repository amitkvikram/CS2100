#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
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

v_Info* bfsv_Info(Graph **G, int root, int goal){
    v_Info *v_InfoPtr;

    v_InfoPtr = (v_Info*)calloc((*G)->V, sizeof(v_Info));
    
    v_InfoPtr[root].dist = 0;
    for(int i=0; i<(*G)->V; i++){
    	v_InfoPtr[i].Checked = false;
    }

    return v_InfoPtr;
}

int allVisited(Graph **G, v_Info **v_I, int vertex){
	(*v_I)[vertex].Checked = true;
	for(int i = 0; i<(*G)->V; i++){
		if(!(*v_I)[i].Checked){
			(*v_I)[vertex].Checked = false;
			return false;
		} 
	}
	
	return true;
}

void freeMemory(Graph **G, v_Info **v_I){
	for(int i=0; i<(*G)->V; i++){
		free((*G)->adjWt[i]);
	}
	free((*G)->adjWt);
	free(*v_I);
	free(*G);
}

void setPrev(Graph **G, v_Info **v_I, queue **Q){
	int current = 0;
	while(!isEmptyQueue(Q)){
		int temp = dequeue(Q);
		(*v_I)[temp].prev = current;
		current = temp;
	}
}

void MakeDot(Graph **G, v_Info **v_I, queue **Q){
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,(*G)->GraphName);
	strcat(GraphName_cp,"_1.dot");
	printf("Output File: %s\n",GraphName_cp);
	fp = fopen(GraphName_cp,"w");
	fprintf(fp, "%s%s%s\n", "graph ",(*G)->GraphName,"{");
	setPrev(G, v_I, Q);

	for(int i=0; i<(*G)->V-1; i++){
		int flag =0;
		for(int j=i; j<(*G)->V; j++){
			if((*G)->adjWt[i][j]>0){
				flag =1;
				if((*v_I)[j].prev==i || (*v_I)[i].prev==j)
					fprintf(fp, "%s%d -- %d%s","\t",i,j,"[color=red];\n");
				else fprintf(fp, "%s%d -- %d%s","\t",i,j,";\n");		//coloring path from root to goal
			}
		}
		if(flag == 0) fprintf(fp, "%s%d%s","\t",i,";\n");
	}
	fprintf(fp, "%s%d%s","\t",(*G)->V-1,"\n");
	fprintf(fp, "%s\n", "}");
	fclose(fp);
}

int isSafe(Graph **G, v_Info **v_I, int vertex, int strtNode){
	for(int i=0; i<(*G)->V; i++){
		if(i!=strtNode && i!=vertex){
			if((*v_I)[i].Checked == false && (*G)->adjWt[vertex][i]>0){
				return 1;
			}
		}
	}

	if((*G)->adjWt[strtNode][vertex] >0 && allVisited(G, v_I, vertex)){
		return 1;
	}
	
	return 0;
}


bool hamiltonian(Graph **G, v_Info **v_I, int vertex, queue **Q){
	if(!isSafe(G, v_I, vertex, 0)){	//checking if it's safe to add vertex means atleast one unvisited vertex is attached to it.
		return false;
	}
	
	if((*G)->adjWt[0][vertex] >0 && allVisited(G, v_I, vertex)){	//if cycle is completed
			enQueue(Q, vertex);
			printf("Status: Cycle completed\n");
			return true;
	}		
	
	(*v_I)[vertex].Checked = true;
	int i = 0;
	
	for(i = 1; i<(*G)->V; i++){		
		if((*G)->adjWt[vertex][i]> 0 && (*v_I)[i].Checked ==false){
			if(hamiltonian(G, v_I, i, Q)){	//callling recursively
				enQueue(Q, vertex);
				return true;
			}
		}		
	}
		
	if(i == (*G)->V){
		(*v_I)[vertex].Checked = false;
		return false;
	}
	
	return true;
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
    v_Info *v_I = bfsv_Info(&G, 0, 0);
    queue *Q = createQueue();
    hamiltonian(&G, &v_I, 0, &Q);
    MakeDot(&G, &v_I, &Q);
    freeMemory(&G, &v_I);
    queueFree(&Q);
}


