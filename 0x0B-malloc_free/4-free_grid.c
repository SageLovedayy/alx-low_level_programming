#include "main.h"
#include <stdlib.h>

/**
* free_grid - frees grid created by alloc_grid func
* @grid: address of 2 dimensional grid
* @height: height of grid
*/
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
