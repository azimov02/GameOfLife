#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int **matrix;

void print(int **matrix,int n,int m){
    printf("\033[H\033[J");//clears output
         puts("");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
     {
         if(matrix[i][j])printf("\e[0;35m");
            else  printf("\e[0;37m");
         printf("%d",matrix[i][j]);
     }
     
        puts("");
    }

        usleep(750000);
}

void next(int **matrix, int n,int m){
int **aux;
aux=(int **)malloc(sizeof(int *)*(n+2));
for(int i=0;i<n+2;i++)
aux[i]=(int *)calloc(m+2,sizeof(int));

for(int i=0;i<n+2;i++)
    for(int j=0;j<m+1;j++)
    aux[i][j]=matrix[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int d=matrix[i-1][j-1]+matrix[i-1][j]+matrix[i-1][j+1]+
            matrix[i][j-1]+matrix[i][j+1]+matrix[i+1][j-1]+
            matrix[i+1][j]+matrix[i+1][j+1];
            if(matrix[i][j]==0 && d==3)aux[i][j]=1;
            if(matrix[i][j]==1 && d!=2 && d!=3)aux[i][j]=0;
        }

for(int i=0;i<n+2;i++)
    for(int j=0;j<m+1;j++)
    matrix[i][j]=aux[i][j];
free(aux);
}

int main(){
int n=10,m=15;
matrix=(int **)malloc(sizeof(int *)*(n+2));
for(int i=0;i<n+2;i++)
matrix[i]=(int *)malloc(sizeof(int)*(m+2));

matrix[5][5]=matrix[5][6]=matrix[5][7]=matrix[5][8]=matrix[5][9]=1;


print(matrix,n,m);
for(int i=0;i<15;i++)
    {
        next(matrix,n,m);
        print(matrix,n,m);
    }

return 0;
}