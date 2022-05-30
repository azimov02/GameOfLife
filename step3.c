#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lib/board.h"
#include "lib/readInput.h"
int main(){
    int n=10,m=10;
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