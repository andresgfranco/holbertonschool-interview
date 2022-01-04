#!/usr/bin/python3
"""
Defines function that can rotate 2D NxN matrix 90 degrees clockwise in place
"""


def rotate_2d_matrix(matrix):
    """
    Rotates 2D NxN matrix 90 degrees clockwise in place
    parameters:
        matrix [list of lists of ints]:
            matrix to rotate
            can be assumed to have 2 dimensions and will not be empty
    """
    # save original row and column size from input matrix
    N = len(matrix)

    # build rotated matrix in a separate matrix_copy
    matrix_copy = []
    copy_row = 0
    for column in range(N):
        for row in range((N - 1), -1, -1):
            if column is 0:
                matrix_copy.append([])
            matrix_copy[copy_row].append(matrix[row][column])
        copy_row += 1

    # copy contents of matrix_copy into matrix
    # since matrix is NxN, do not need to resize matrix for rotation
    for row in range(N):
        for column in range(N):
            matrix[row][column] = matrix_copy[row][column]
