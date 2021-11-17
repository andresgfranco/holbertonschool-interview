#!/usr/bin/python3
"""This module contais the rain function
"""


def less_number(num1, num2):
    """returns the less number
    """
    if num1 > num2:
        return num2
    return num1


def count_water(i, wall, walls, sunken_walls):
    """make the operation to count the wather"""
    tmp_water = i - (wall + 1)
    tmp_water *= less_number(walls[wall], walls[i])
    tmp_water -= sum(sunken_walls[wall + 1: i])

    return tmp_water


def rain(walls):
    """calculates how many square units of water
        will be retained after it rains.

    Args:
        walls (list): is a list of non-negative integers.
    """
    total_water = 0
    wall = None
    sunken_walls = []
    higher_wall = None

    if not walls:
        return 0

    i = 0
    while i < len(walls):
        if walls[i] == 0:
            sunken_walls.append(0)
        else:
            if wall is None:
                wall = i
                sunken_walls.append(0)
            else:
                if walls[wall] > walls[i]:
                    if higher_wall is None:
                        higher_wall = i
                    if walls[i] > walls[higher_wall]:
                        higher_wall = i
                    sunken_walls.append(walls[i])
                else:
                    total_water += count_water(i, wall, walls, sunken_walls)

                    wall = i
                    higher_wall = None
                    sunken_walls.append(0)

        if i + 1 == len(walls):
            if higher_wall:
                i = higher_wall
                total_water += count_water(i, wall, walls, sunken_walls)

                wall = i
                higher_wall = None
                sunken_walls.append(0)

        i += 1

    return total_water
