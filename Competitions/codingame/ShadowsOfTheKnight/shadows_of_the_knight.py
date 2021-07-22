import sys
import math

w, h = [int(i) for i in input().split()]
n = int(input())  # maximum number of turns before game over.
i, j = [int(i) for i in input().split()]
def divide(a, b, p):
    r = [
        [(a[0], a[1]), (a[0], p[1] - 1), (p[0], p[1] - 1), (p[0], a[1])],
        [(a[0], p[1]), (a[0], b[1]), (p[0], b[1]), (p[0], p[1])],
        [(p[0] + 1, p[1]), (p[0] + 1, b[1]), (b[0], b[1]), (b[0], p[1])],
        [(p[0] + 1, 0), (p[0] + 1, p[1] - 1), (b[0], p[1] - 1), (b[0], 0)]
        ]
    return r
a = (0, 0)
b = (h - 1, w - 1)
p = (i, j)
r = divide(a, b, p)
while True:
    dir = input()  # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
    if dir == 'U':
        p = (p[0] - (p[0] - a[0]) // 2, p[1])
        b = (p[0], b[1])
    elif dir=='UR':
        p = (p[0] - (p[0] - a[0]) // 2, p[1] + (b[1] - p[1]) // 2)
        a = (a[0], p[1])
        b = (p[0], b[1])
    elif dir == 'R':
        p = ()
    elif dir == 'DR':
        pass
    elif dir == 'D':
        pass
    elif dir == 'DL':
        pass
    elif dir == 'L':
        pass
    elif dir == 'UL':
        pass
    r = divide(a, b, p)
    print(p[0], p[1])

