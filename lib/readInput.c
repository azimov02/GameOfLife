#include "readInput.h"

void read_file_in_matrix(int**matrix){
    FILE* fp=fopen("matrix.txt","r");
     if (NULL == fp) {
        fp=fopen("../matrix.txt","r");
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
