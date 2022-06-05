#include "readInput.h"
#include <stdlib.h>
int ** read_file_in_matrix(char * filename,int *n,int *m){
    FILE* fp=fopen(filename,"r");
     if (NULL == fp) {
        puts("File is not found");
        return NULL;
    }
   int *aux,size=10000;
   aux=(int *)malloc(size*sizeof(int));
    int a=0,b=0,i=0;
    *n=0,*m=0;
    char ch;
    do {
        ch=fgetc(fp);
        
        if(ch =='\n'){
            a++;
            *m=b;
            b=0;
            //printf("\n");
        }
        else if (ch=='1'||ch=='0'){
            aux[i]=ch-48;
           // printf("%d",matrix[a][b]);
            b++;
            i++;
        }
        
    } while (ch != EOF);
  *n=i/(*m);
  int **matrix;
    matrix=(int **)malloc(sizeof(int*)*(*n));
   for(int i=0;i<(*n);i++)
    matrix[i]=(int *)malloc(sizeof(int)*(*m));

    for(int i=0;i<(*n);i++)
      for(int j=0;j<(*m);j++)
      matrix[i][j]=aux[(*m)*i+j];

    //   for(int i=0;i<*n;i++){puts("");
    // for(int j=0;j<*m;j++)printf("%d ",matrix[i][j]);}
    free(aux);
   return matrix;
}
