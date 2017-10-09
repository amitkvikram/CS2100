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
	fscanf(*fp, " %[^\n]s", GraphName);
	char GraphType[50];
	fscanf(*fp, " %[^\n]s", GraphType);
	int num_vertices;
	fscanf(*fp, "%d", &num_vertices);
	printf("vertices= %d",num_vertices);
	
	for(int i=0;i<num_vertices; i++){
		for(int j=0;j<num_vertices;j++){
			fscanf(*fp, "%1d", &arr[i][j]);
		}
	}
	
	MakeDot( num_vertices, GraphName);
}	

int main(){
	char FileName[50];
	printf("Enter Filename");
	scanf("%s", FileName);
	
	FILE *fp;
	fp=fopen(FileName, "r");
	
	 
	 if(fp==0)
	 {
	  	printf("Error in opening the file %s.\n", FileName);
	  	return(1);
	 }
	
	Read(&fp);
	return 0;
}
	 
