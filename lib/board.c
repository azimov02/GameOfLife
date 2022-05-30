#include "board.h"

void print(int **matrix,int n,int m){
    printf("\033[H\033[J");//clears output
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
		{   
             if(matrix[i][j])printf("\e[41m  ");
            else  printf("\e[100m  ");
            //if(matrix[i][j])
            //printf("%d",matrix[i][j]);
            //else  {
                
            //}
		}
			printf("\e[0m  ");
        puts("");
	}
    usleep(750000);
}

void next(int **matrix, int n,int m){
    int **aux;
    aux=(int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++)
    aux[i]=(int *)calloc(m,sizeof(int));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            aux[i][j]=matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int d=0;
            d+=matrix[((i-1+n)%n)][(j-1+m)%m];
            d+=matrix[(i-1+n)%n][j];
            d+=matrix[(i-1+n)%n][(j+1)%m];
            d+=matrix[i][(j-1+m)%m];
            d+=matrix[i][(j+1)%m];
            d+=matrix[(i+1)%n][(j-1+m)%m];
            d+=matrix[(i+1)%n][j];
            d+=matrix[(i+1)%n][(j+1)%m];
            if(matrix[i][j]==0 && d==3)aux[i][j]=1;
            if(matrix[i][j]==1 && d!=2 && d!=3)aux[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matrix[i][j]=aux[i][j];
        }
    }
    free(aux);
}
