#!/usr/bin/python3

"""
Log Parser
"""


import sys


total_file_size = {'size': 0}
codes = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}


def print_data():
    """
        Prints the resume
    """
    print('File size: {}'.format(total_file_size['size']))
    for key in sorted(codes.keys()):
        if codes[key] > 0:
            print('{}: {}'.format(key, codes[key]))


def operate_resume(line):
    """
        Operates with the resume stats
    """
    try:
        line = line.split(' ')
        size = line[-1]
        total_file_size['size'] += int(size)
        if line[-2] in codes:
            codes[line[-2]] += 1
    except Exception as e:
        pass


if __name__ == '__main__':
    num_lines = 1
    try:
        for line in sys.stdin:
            operate_resume(line)
            if num_lines % 10 == 0:
                print_data()
            num_lines += 1
    except KeyboardInterrupt:
        print_data()
        raise
    print_data()
