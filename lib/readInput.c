#include "readInput.h"
#include <string.h>
#include <stdlib.h>
/**
 * @brief Reads start configuration from txt files and turns it into the matrix of 0 and 1
 * @param filename the name of the configuration
 * @param n number of rows
 * @param m number of columns
 * @return int** returns pointer to the created matrix 
 * 
 * This function gets as parameters the name of file which contains one of possible start configurations of the game. 
 *Then it allocates memory to create a matrix and copy the contents of the file to that matrix. In addition it writes
 *the values of rows and colums to n and m. In case if file was not found it returns NULL pointer.
 * 
 * 
 * 
 */
int ** read_file_in_matrix(char * filename,int *n,int *m){
    char location1[100]="../start_configs/";
    char location2[100]="./start_configs/";
    for(int i=0;i<strlen(filename);i++){
      location1[i+17]=filename[i];
      location2[i+16]=filename[i];
    }
    FILE* fp=fopen(location1,"r");
    if(fp==NULL){
      fp=fopen(location2,"r");
    }
     if (fp==NULL) {
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
        }
        else if (ch=='1'||ch=='0'){
            aux[i]=ch-48;
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

    free(aux);
   return matrix;
}
