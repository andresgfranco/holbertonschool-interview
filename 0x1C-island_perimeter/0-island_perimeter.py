#!/usr/bin/python3
"""This module contains the island_perimeter function
"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in grid
    """
    if grid == []:
        return

    height = len(grid)
    width = len(grid[0])
    perimeter = 0

    i, j = 0, 0

    while i < height:
        j = 0

        while j < width:
            if grid[i][j] == 1:
                perimeter += check_perimeter(grid, i, j)

            j += 1

        i += 1

    return perimeter


def check_perimeter(grid, i, j):
    """Checks if there are water(number 0) around the number 1
    """
    height = len(grid)
    width = len(grid[0])
    perimeter = 0

    if (j + 1) < width:
        if grid[i][j + 1] == 0:
            perimeter += 1
    else:
        perimeter += 1

    if j - 1 >= 0:
        if grid[i][j - 1] == 0:
            perimeter += 1
    else:
        perimeter += 1

    if i + 1 < height:
        if grid[i + 1][j] == 0:
            perimeter += 1
    else:
        perimeter += 1

    if i - 1 >= 0:
        if grid[i - 1][j] == 0:
            perimeter += 1
    else:
        perimeter += 1

    return perimeter
