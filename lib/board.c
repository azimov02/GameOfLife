#include "board.h"
#include <SDL2/SDL.h>
#include <assert.h>
#include <stdbool.h>
/**
 * @brief Displays board
 * @param matrix  board
 * @param n number of rows
 * @param m number of columns
 * 
 * This function creates window where it prints the board every 500ms. Then it uses next() functionc to get the next state of the game.
 * This process keep repeating until the user presses X on the window.
 */
void display(int **matrix,int n,int m){

int frame_delay = 500;
int max=n>m?n:m;
int cell_width = 800/max;
int margin=10,window_heigth=cell_width*n,window_width=cell_width*m;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Error at SDL initialization\n");
		exit(1);
	}
	SDL_Window* window = SDL_CreateWindow("Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width+2*margin, window_heigth+2*margin,
						  SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	assert (renderer != NULL);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				free(matrix);
				break;
			}
		}	
	if(quit)break;
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	SDL_RenderClear(renderer);


	SDL_SetRenderDrawColor(renderer, 0,255,0,255);

	SDL_Rect rect={0,0,cell_width,cell_width};

	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j)
		{
			if(matrix[i][j])
			{
				rect.x=margin+j*cell_width; 
				rect.y=margin+i*cell_width;
				SDL_RenderFillRect(renderer, &rect);
			}
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(frame_delay);
		next(matrix,n,m);
}
	
  	SDL_Quit();

}


/**
 * @brief Returns state of the board at time t+1
 * @param matrix  board
 * @param n number of rows
 * @param m number of columns
 * The matrix signifies the state of board at time t. This function creates auxiliary matrix that will contains state of the board at time t+1.
 *Rules of the game are applied to the original matrix to fill the auxiliary matrix. The the contents of aux matrix are copied to the original one.
 *Thus matrix contains state at time t+1 
 * 
 */

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

