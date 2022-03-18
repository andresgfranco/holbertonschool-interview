#!/usr/bin/python3
"""This module contains the pascal_triangle function
"""


def pascal_triangle(n):
    """returns a list of lists of integers
        representing the Pascal’s triangle of n:
    """
    pascal_triangle_list = []

    if n <= 0:
        return pascal_triangle_list

    for i in range(n):
        pascal_triangle_list.append([])
        pascal_triangle_list[i].append(1)

        for j in range(i):
            previous_row = pascal_triangle_list[i - 1]

            if j != i - 1:
                pascal_triangle_list[i].append(
                    previous_row[j] + previous_row[j + 1]
                )
            else:
                pascal_triangle_list[i].append(1)

    return pascal_triangle_list
