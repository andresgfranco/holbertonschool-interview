#!/usr/bin/python3
'''Module for function canUnlockAll'''


def canUnlockAll(boxes):
    '''Function that determines if a list of boxes can be opened'''
    lenList = len(boxes)
    boxesNumbersList = []
    boxesNumbersListCopy = []
    boxNumber = 1
    canUnlock = True

    for i in range(lenList):
        boxesNumbersList.append(i)

    for i, box in enumerate(boxes, start=1):
        if i >= lenList:
            break
        for j, keyFinder in enumerate(boxes):
            if i == j:
                j = j+1
            if j == lenList:
                break
            if boxNumber in keyFinder and len(boxes[j]) > 0:
                boxesNumbersList[i] = "opened"
                break
        boxNumber = boxNumber + 1

    boxesNumbersList[0] = "opened"

    for box in boxesNumbersList:
        if box != "opened":
            return False

    return True