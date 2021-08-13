#!/usr/bin/python3
'''
Method that calculates the fewest
number of operations needed to result in exactly
n H characters in the file
'''


def minOperations(n):
    primeNumber = 2
    minOperations = 0

    if n <= 1:
        return 0
    else:
        while n != 1:
            if n % primeNumber == 0:
                n = n / primeNumber
                minOperations = minOperations + primeNumber
            else:
                primeNumber = primeNumber + 1

    return minOperations
