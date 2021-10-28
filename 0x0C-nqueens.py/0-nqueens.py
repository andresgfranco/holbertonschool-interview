#!/usr/bin/python3


from sys import argv


if len(argv) != 2:
    print("Usage: nqueens N")
    exit(1)

n_queens = argv[1]

try:
    n_queens = int(n_queens)
except ValueError:
    print("N must be a number")
    exit(1)

if n_queens < 4:
    print("N must be at least 4")
    exit(1)

non_attacking_queens = []
rows_attacked = []
cols_attacked = []


def is_safe(new_queen):
    if new_queen[0] in cols_attacked:
        return False
    if new_queen[1] in rows_attacked:
        return False

    """ Checks diagonal up left """
    i = new_queen[0]
    j = new_queen[1]
    while i >= 0 and j >= 0:
        if [i, j] in non_attacking_queens:
            return False

        i -= 1
        j -= 1

    """ Checks diagonal up right """
    i = new_queen[0]
    j = new_queen[1]
    while j < n_queens and i >= 0:
        if [i, j] in non_attacking_queens:
            return False

        i -= 1
        j += 1

    return True


def search_queens(col_start):
    for i in range(n_queens):
        if i != 0:
            col_start = 0
        for j in range(col_start, n_queens):
            if [i, j] not in non_attacking_queens:
                if is_safe([i, j]):
                    non_attacking_queens.append([i, j])
                    cols_attacked.append(i)
                    rows_attacked.append(j)

    return non_attacking_queens


def finds_all_possibilities():
    col_start = 0

    while True:
        non_attacking_queens.clear()
        rows_attacked.clear()
        cols_attacked.clear()
        possible_solution = search_queens(col_start)
        """ print(possible_solution) """

        if len(possible_solution) == n_queens:
            print(possible_solution)

        col_start += 1

        if col_start == n_queens:
            break


finds_all_possibilities()
