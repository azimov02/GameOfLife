#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


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
            if(i && j)d+=matrix[i-1][j-1];
            if(i)d+=matrix[i-1][j];
            if(i && j<m-1)d+=matrix[i-1][j+1];
            if(j)d+=matrix[i][j-1];
            if(j<m-1)d+=matrix[i][j+1];
            if(i<n-1 && j)d+=matrix[i+1][j-1];
            if(i<n-1)d+=matrix[i+1][j];
            if(i<n-1 && j<m-1)d+=matrix[i+1][j+1];
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
void read_file_in_matrix(int**matrix){
    FILE* fp=fopen("matrix.txt","r");
    if (NULL == fp) {
        fp=fopen("./start_configs/heart.txt","r");
    }
    int a=0,b=0;
    char ch;
    do {
        ch=fgetc(fp);
        
        if(ch =='\n'){
            a++;
            b=0;
            //printf("\n");
        }
        else if (ch=='1'||ch=='0'){
            matrix[a][b]=ch-48;
           // printf("%d",matrix[a][b]);
            b++;
        }
        
    } while (ch != EOF);
}
int main(){
    int n=12,m=12;
    int **matrix;
    matrix=(int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
    matrix[i]=(int *)malloc(sizeof(int)*m);

    // matrix[5][5]=matrix[5][6]=matrix[5][7]=matrix[5][8]=matrix[5][9]=1;
    
    read_file_in_matrix(matrix);
    
    
    
    print(matrix,n,m);
    for(int i=0;i<15;i++)
    {
        next(matrix,n,m);
        print(matrix,n,m);
    }

    return 0;
}
