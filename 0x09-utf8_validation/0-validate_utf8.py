#!/usr/bin/python3
"""UTF-8"""


def validUTF8(data):
    """
    method that determines if a given data set
    represents a valid UTF-8 encoding
    Prototype: def validUTF8(data)
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    nbytes = 0

    byte1 = 1 << 7
    byte2 = 1 << 6

    for number in data:
        b = 1 << 7
        if nbytes == 0:
            while b & number:
                nbytes += 1
                b = b >> 1
            if nbytes == 0:
                continue
            if nbytes == 1 or nbytes > 4:
                return False
        else:
            if not (number & byte1 and not (number & byte2)):
                return False
        nbytes -= 1
    return nbytes == 0
