#!/usr/bin/python3
""" The N queens puzzle is the challenge of placing N
     non-attacking queens on an N×N chessboard.
     Write a program that solves the N queens problem."""

import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
if not sys.argv[1].isdigit():
    print("N must be a number")
    exit(1)
if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)
N = int(sys.argv[1])
board = [[0 for i in range(N)]for j in range(N)]
k = 1


def print_sol(board):
    """ Method Print"""
    global k
    k = k + 1
    S = []
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                S.append([i, j])
    print(S)


def isSafe(board, row, col):
    """ Method IsSafe """
    for i in range(col):
        if (board[row][i]):
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while j >= 0 and i < N:
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1
    return True


def solving(board, col):
    """ Method Solving """
    if (col == N):
        print_sol(board)
        return True
    res = False
    for i in range(N):
        if (isSafe(board, i, col)):
            board[i][col] = 1
            res = solving(board, col + 1) or res
            board[i][col] = 0
    return res


def solve():
    """ Method Solve"""
    board = [[0 for j in range(N)]for i in range(N)]
    if (solving(board, 0) is False):
        print("Solution does not exist")
        return
    return


solve()
