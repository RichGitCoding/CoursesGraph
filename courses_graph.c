
#include "stdio.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>



int search( char classes[], char vertex[] )
{
	
	
	char *tmp;
	//printf("%s\n",classes);
	tmp = strstr(classes,vertex);
	//printf("%s\n",classes);
	if(tmp != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void dfs(int numberOfLines,int G[numberOfLines][numberOfLines], int u, int* time, int color[], int* pred, int *d, int *finish)
{
	int c = u;
	(*time) = (*time) +1;
	d[c] = *time;
	color[c] = 2;
	int v = 0;
	
	for(v = 0; v< c; v++)
	{
		if( color[v] == 1)
		{
			pred[v] = c;
			dfs(numberOfLines,G, v, time,color,pred,d,finish); 
		}
	}
	
	color[c] = 3;
	(*time) = (*time) +1;
	finish[c] = *time;
	
	printf("node %d: (%d,%d)\n",c,d[c],finish[c]);
	//printf("%d\n" , d[c]);
	//printf("%d\n",finish[c]);
}

int main(int argc, char* argv)
{
	//get file 
	printf("Please enter a a file name-->");
	char* filename = (char *)malloc(sizeof(char)*30);
	scanf("%s",filename);
	
	//test file
	FILE * test;
	if((test = fopen(filename,"r")))
	{
		fclose(test);
	}
	else
	{
		printf("File not valid\n\n");
		exit(0);
	}
	
	//open 2 files, onw to get number of lines 
	FILE* file= fopen(filename,"r");
	FILE* lineFile= fopen(filename,"r");
	FILE* nextFile = fopen(filename, "r");
	
	//count number of lines in the file
	
	int numberOfLines=0;
	char sub[101];
	while(fgets(sub,sizeof(sub),lineFile))
	{
		numberOfLines++;
		
	}
	
	fclose(lineFile);
	
	//printf("\n%d",numberOfLines);
	
	//create array to store the words in an array
	char classes[numberOfLines][1001];
	char vertex[numberOfLines][31];
	
	//read in each line of the file
	char line[1001];
	char *tok;
	int i, j=0;
	for(i = 0; i<numberOfLines;i++)
	{
		fgets(line, 1001, file);
		strcpy(classes[i],line);
		//printf("%s\n",line);
		//tok = strtok(line," ");
		//printf("%s",tok);
		//strcpy(vertex[i], tok);
		//printf("%s",vertex[i]);
		//strcpy(classes[i],line);
		tok = NULL;
	}
	fclose(file);
	
	FILE* hi= fopen(filename,"r");
	char *the;
	char no[1000];
	for(i =0; i< numberOfLines; i++)
	{
		fgets(no, 1000, hi);
		//printf("%s\n",no);
		the = strtok(no, "  , \n");
		//printf("%s\n", the);
		strcpy(vertex[i], the);
		the = strtok(NULL," ");
	}
	fclose(hi);
	
	/*
	for(i = 0; i<numberOfLines; i++)
	{
		printf("%s",classes[i]);
		
		
	}
	
	for(i = 0; i<numberOfLines; i++)
	{
		printf("\n%s",vertex[i]);
		
		
	}
	*/
	//only what is left after 
	
	char subarr[numberOfLines][1000];
	FILE* arrFile = fopen(filename, "r");
	char line3[1000];
	char *ret = NULL;
	for(i = 0; i<numberOfLines;i++)
	{
		fgets(line3, 1001, arrFile);
		
		//strcpy(classes[i],line);
		ret = strchr(line3,' ');
		//printf("%s",ret);
		if(ret!= NULL)
		{
			strcpy(subarr[i], ret);
		}
		//strcpy(classes[i],line);
		
	}
	fclose(arrFile);
	
	//remove spaces at start of string
	int c=0,v=0,x=0;
	char huh = ' ';
	/*
	for(c = 0; c<numberOfLines; c++)
	{
		for(v = 0; v< 1000; v++)
		{
			if( subarr[c][v] != huh )
			{
				subarr[c][x++] = subarr[i][v]; 
			}
		}
		//printf("%s\n", subarr[i]);
		
		subarr[c][x] = '\0';
	}	
	*/
	FILE* File2 = fopen(filename, "r");
	char actarr[numberOfLines][1000];
	char line4[1000];
	
	for(i = 0; i<numberOfLines;i++)
	{
		fgets(line4, 1001, File2);
		strcpy(actarr[i],line4);
		//printf("%s\n", actarr[i]);
	}
	fclose(File2);
	
	
	
	
	
	char line2[31];
	char arr[30][1000];
	i = 0;
	//store vertexes
	
	
	while(!feof(nextFile))
	{
		
		fgets(line2, 31, nextFile);
		tok = strtok(line2," ");
		while(tok!=NULL)
		{	
			strcpy(arr[i], tok);
			//printf("\n%s", arr[i]);
			tok = strtok(NULL, " ");
			i++;
			
		}
		
		
	}
	int numberOfCourses=i;
	fclose(nextFile);
	
	
	//adjacency matrix
	//printf("%d\n", numberOfLines);
	int adj[numberOfLines][numberOfLines];
	int a,b;
	for(a =0; a<numberOfLines;a++)
	{
		for(b =0; b<numberOfLines; b++)
		{
			adj[a][b] = 0;
		}
	}
	
	//change the entire array into numbers
	
	printf("\nNumber of verticies: %d\n", numberOfLines);
	
	printf("Vertex correspondence:\n");
	for(a =0; a< numberOfLines; a++)
	{
		printf(" %d = %s \n", a, vertex[a]); 
	}
	
	//find way to fill out adjacency matrix
	//eliminate the first space in mini array
	
	char temp;
	
	for(a =0; a< numberOfLines; a++)
	{
		for(b = 0; b< 1000; b++)
		{
			subarr[a][b] = subarr[a][b+1];
		}
		//printf("%s\n" , subarr[a]);
	}
	
	for(a=0; a<numberOfLines;a++)
	{
		//printf("%s\n" , actarr[a]);
	}
	

	
	int solve=0;
	for(a = 0; a< numberOfLines; a++)
	{
		for( b = 0; b< numberOfLines; b++)
		{
			if( a!=b )
			{
				//printf("%s\n" , actarr[b]);
				solve = search( actarr[b], vertex[a]);//if 1, you found the class at that vertex
			}
			
			adj[a][b] = solve;
			
			//printf("%d\n", solve);
			solve =0;
		}
		
		
	}
	char *ds = " ";
	printf("\nMatrix:\n");
	printf("%8s|", ds);
	for( i =0; i< numberOfLines; i++)
	{
		printf("%6d ",i);
	}
	printf("\n");
	
	for(j = 0; j< numberOfLines; j++)
	{
		printf("--------------");
	}
	
	
	
	for(a = 0; a< numberOfLines; a++)
	{
		printf("\n");
		printf(" %6d", a);
		for(b = 0; b< numberOfLines; b++)
		{
			printf("%6d |", adj[a][b]);
		}
		
	}
	printf("\n");
	
	//figure out dfs
	
	int time = 0;
	int color[3];//1 is white, 2, is grey, 3 is black
	int pred[numberOfLines];
	int d[numberOfLines];
	int finish[numberOfLines];
	int u =0;
	for(i =0; i<numberOfLines;i++)
	{
		color[i] = 1;
		pred[i] = 0;
		d[i] = -1;
		finish[i] = -1;
	}
	
	
	for( u =0; u< numberOfLines; u++)
	{
		dfs(numberOfLines,adj,u, &time,color,pred,d,finish);
	}
	//print in order
	printf("In order:\n");
	for(i = 0; i< numberOfLines; i++)
	{
		printf("\n%d : %s - vertex %d\n",i, vertex[i],i);
	}
	
	free(filename);
	
	
	return 0;
}
