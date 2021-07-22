from math import ceil
for i in range(1, 10):
    for j in range(i + 1, i + 10):
        val = (i**2 + j**2 + i + j - i*j) /(i + j)
        print(i, j, ceil(val))