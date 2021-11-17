#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]  # 6
    print(rain(walls))
    walls = [2, 0, 0, 4, 0, 0, 1, 0]  # 6
    print(rain(walls))
    walls = [0, 0, 0, 0, 0, 0, 0, 0]  # 0
    print(rain(walls))
    walls = [2, 1, 3, 0, 0, 0, 0, 0]  # 1
    print(rain(walls))
    walls = [2, 1, 3, 0, 0, 0, 1, 0]  # 4
    print(rain(walls))
    walls = [7, 6, 5, 4, 3, 2, 1, 0]  # 0
    print(rain(walls))
    walls = [0, 1, 2, 3, 4, 5, 6, 7]  # 0
    print(rain(walls))
    walls = [7, 0, 5, 0, 3, 0, 1, 0]  # 9
    print(rain(walls))
