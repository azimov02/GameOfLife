#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "CUnit/Basic.h"

static FILE* temp_file = NULL;
int read_file_in_matrix(int**matrix);
void next(int **matrix, int n,int m);
void print(int **matrix,int n,int m);

int init_suite1(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}

/**
 * @brief Tests print() function 
 * 
 * testPRINT function tests whether matrix will be successfully printed and won't be null
 */
void testPRINT(void){
   int n=10,m=10;
    int **matrix;
    matrix=(int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
    matrix[i]=(int *)malloc(sizeof(int)*m);
   print(matrix,n,m);
   CU_ASSERT(matrix!=NULL);
}
/**
 * @brief Tests next() function 
 * 
 * testNEXT function tests whether matrix will be filled correctly and won't return NULL after
 * function call
 */
void testNEXT(void){
   int n=10,m=10;
   int **matrix;
   matrix=(int **)malloc(sizeof(int*)*n);
   for(int i=0;i<n;i++)
   matrix[i]=(int *)malloc(sizeof(int)*m);
   next(matrix,5,5);
   CU_ASSERT(matrix!=NULL);
}
/**
 * @brief Tests read_file_in_matrix() function 
 * 
 * testREAD_FILE_IN_MATRIX function tests whether matrix will be successfully filled from
 * one of the start configuration files
 */
void testREAD_FILE_IN_MATRIX(){
   int n=10,m=10;
   int **matrix;
   matrix=(int **)malloc(sizeof(int*)*n);
   for(int i=0;i<n;i++)
   matrix[i]=(int *)malloc(sizeof(int)*m);
   int v=read_file_in_matrix(matrix);
   CU_ASSERT(v!=-1);

}

int main()
{
   CU_pSuite clientSuite = NULL,serverSuite=NULL;
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   clientSuite = CU_add_suite("Client_Suite", init_suite1, clean_suite1);
   serverSuite = CU_add_suite("Server_Suite", init_suite1, clean_suite1);
   if (NULL == clientSuite||NULL==serverSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }
   if (NULL == CU_add_test(clientSuite, "test of print()",testPRINT)
      || NULL == CU_add_test(serverSuite, "test of read_file_in_matrix()",testREAD_FILE_IN_MATRIX )
      ||NULL == CU_add_test(serverSuite, "test of next()",testNEXT )
   )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}


void print(int **matrix,int n,int m){
   printf("\033[H\033[J");
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
		{   
             if(matrix[i][j])printf("\e[41m  ");
            else  printf("\e[100m  ");
        
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

int read_file_in_matrix(int**matrix){
   FILE* fp=fopen("heart.txt","r");
   if (NULL == fp) {
      fp=fopen("../start_configs/heart.txt","r");
   }
   if (fp==NULL)
   {
      return -1;
   }
   
   
   int a=0,b=0;
   char ch;
   do {
      ch=fgetc(fp);
      
      if(ch =='\n'){
         a++;
         b=0;
      }
      else if (ch=='1'||ch=='0'){
         matrix[a][b]=ch-48;
         b++;
      }
      
   } while (ch != EOF);
   return 1;
}
