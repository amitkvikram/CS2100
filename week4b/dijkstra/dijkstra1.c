/*
   Name: Amit Vikram Singh
   Roll No: 111601001
   Date: 31/10/2017
   Task: dijkstra.c
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

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

	G->components = 0;
	G->isolated = 0;

	return G;
}

v_Info* bfsv_Info(Graph *G, int root, int goal){
	v_Info *v_InfoPtr;

	v_InfoPtr = (v_Info*)malloc(G->V * sizeof(v_Info));

	  for(int i = 0; i<G->V; i++){
	    v_InfoPtr[i].dist = 100000;
	    v_InfoPtr[i].Checked = false;
	    v_InfoPtr[i].connected_to_goal = 0;
	  }
	v_InfoPtr[root].dist = 0;
	v_InfoPtr[root].prev = 0;
	return v_InfoPtr;
}

//Creating dot file
void MakeDot(Graph *G,v_Info *v_I, int x, int y){
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,G->GraphName);
	strcat(GraphName_cp,"new.dot");
	printf("Output: %s\n",GraphName_cp);
	fp = fopen(GraphName_cp,"w");
	fprintf(fp, "%s%s%s\n", "graph ",G->GraphName,"{");
	for(int i=0; i< G->V-1; i++){
		for(int j=i; j<G->V; j++){
			if(G->adjWt[i][j]>0){
			if(v_I[j].connected_to_goal == 1 && (i == v_I[j].prev || j == v_I[i].prev) && v_I[i].connected_to_goal == 1){
			 fprintf(fp, "%s%d -- %d%s%d%s","\t",i,j,"[color =red][label=",G->adjWt[i][j],"];\n");
			 }
			else fprintf(fp, "%s%d -- %d%s","\t",i,j,";\n");
			}
		}
	}
	fprintf(fp, "%s%d%s","\t",G->V-1,"\n");

	fprintf(fp, "%s\n", "}");
}

//Checking if all vertex has been visited
int allVisited(Graph *G, v_Info *v_I){
	for(int i = 0; i<G->V; i++){
		if(v_I[i].Checked == false) return 0;
	}
	
	return 1;
}

//To find the vertex which is unvisted and is at the minimum distance from source
int minArray(Graph *G, v_Info *v_I){
	int min = 100000;
	int index = 0;
	for(int i =0; i<G->V; i++){
		if(v_I[i].Checked == false && v_I[i].dist<min)
		{
			min = v_I[i].dist;
			index = i;
		}
	}
	
	return index;
}

//printing shortest path between x and y
void printPath(Graph *G, v_Info *v_I, int x, int y){
	int count = v_I[y].dist;
	while(y!=x){
		printf("%d ",y);
		v_I[y].connected_to_goal = 1;
		y = v_I[y].prev;
	}
	
	printf("%d \n",y);
	v_I[y].connected_to_goal = 1;
}

//dijkstra algorihtm to find shortest path between x and y
void dijkstra(Graph *G, v_Info *v_I,int x, int y){
	while(!(allVisited(G, v_I))){
		int minDist = minArray(G, v_I);
		v_I[minDist].Checked = true;
		
		for(int i =0; i<G->V; i++){
			if(G->adjWt[minDist][i]>0 && v_I[i].Checked ==false){
			
				int temp = v_I[minDist].dist + G->adjWt[minDist][i];
				if(temp < v_I[i].dist){   //Checking if a new shortes path to vertex i exists
					v_I[i].prev = minDist;
					v_I[i].dist = temp;
				}
			}
		}
	}
	
	printf("Distance: %d\n", v_I[y].dist);
	printf("Path is: ");
	
	printPath(G, v_I,x, y);//fundtion to print path
	MakeDot(G, v_I, x, y); //fundtion to make dot file

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
	int x, y;
	printf("Enter x and y: ");
	scanf("%d%d", &x, &y);
	fclose(fp);
	v_Info *v_I = bfsv_Info(G, x, y);
	dijkstra(G, v_I, x, y);
	return 0;

}
//main ends here
