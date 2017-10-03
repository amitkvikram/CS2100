/*
   Name: Amit Vikram Singh
   Roll No: 111601001
   Date: 03/10/2017
   Task: 01
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[100][100];

//Creating dot file
void MakeDot(int num_vertices, char *GraphName){	
	FILE *fp;
	char GraphName_cp[50];
	strcpy(GraphName_cp,GraphName);
	strcat(GraphName,".dot");
	fp = fopen(GraphName,"w");
	fprintf(fp, "%s%s%s\n", "graph ",GraphName_cp,"{");
	for(int i=0; i<num_vertices-1; i++){
		for(int j=i; j<num_vertices; j++){
			if(arr[i][j]==1){
			fprintf(fp, "%s%d -- %d%s","\t",i,j,";\n");
			}
		}
	}
	fprintf(fp, "%s%d%s","\t",num_vertices-1,"\n");
	fprintf(fp, "%s\n", "}");
}

void Read(FILE **fp){	
	char GraphName[50] ;
	fscanf(*fp, " %[^\n]s", GraphName);	//Name of the graph written at beginning of .txt file
	char GraphType[50];
	fscanf(*fp, " %[^\n]s", GraphType);
	int num_vertices;
	fscanf(*fp, "%d", &num_vertices);	//Number of vertices in Graph
	printf("vertices= %d",num_vertices);
	
	for(int i=0;i<num_vertices; i++){  		//Reading Graph Vertices
		for(int j=0;j<num_vertices;j++){
			fscanf(*fp, "%1d", &arr[i][j]);
		}
	}
	
	MakeDot( num_vertices, GraphName);	//Calling MakeDot to crete .dot file
}	

//Main Begins Here
int main(){
	char FileName[50];
	printf("Enter Filename");
	scanf("%s", FileName);
	
	FILE *fp;
	fp=fopen(FileName, "r");	//Opening .txt file
	
	 
	 if(fp==0)	//If error in occured in opening file
	 {
	  	printf("Error in opening the file %s.\n", FileName);
	  	return(1);
	 }
	
	Read(&fp);
	return 0;
}
//Main Ends Here 
