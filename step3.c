#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lib/board.h"
#include "lib/readInput.h"
int main(int argc, char * argv[]){
    int **matrix,n,m;
    
    if(argc==1)matrix=read_file_in_matrix("pulsar.txt",&n,&m);
    else matrix=read_file_in_matrix(argv[1],&n,&m);

   if(matrix==NULL){
    puts("There is no such start configuration");
    return 1;
   }

    display(matrix,n,m);

    return 0;
}
