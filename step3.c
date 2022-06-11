#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lib/board.h"
#include "lib/readInput.h"
int main(){
    int **matrix,n,m;
    
    matrix=read_file_in_matrix("../start_configs/pulsar.txt",&n,&m);//reading configuration from file

    printf("%d %d\n",n,m);
    // for(int i=0;i<n;i++){puts("");for(int j=0;j<m;j++)printf("%d",matrix[i][j]);}
    display(matrix,n,m);

    return 0;
}
