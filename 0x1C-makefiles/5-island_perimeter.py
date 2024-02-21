#!/usr/bin/python3
"""
island perimeter module
"""


def island_perimeter(grid):
    """
    returns perimeter of island described in grid
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:  # Check if cell has neighbor to the top
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:  # Check if cell has neighbor to the left
                    perimeter -= 2

    return perimeter
