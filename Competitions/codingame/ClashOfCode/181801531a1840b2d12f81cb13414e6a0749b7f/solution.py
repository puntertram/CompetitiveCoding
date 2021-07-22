n=int(input())
grid=[]
for i in range(n):
    line = input().split()
    grid += line, 
gr = grid.copy()
for i, r in enumerate(grid):
    for j, c in enumerate(r):
        if c == 'b':
            continue
        gr[i][j] = sum(w[j+j%~j:j+2].count('b') for w in grid[i+i%~i:i+2])

for i in gr:
    print(*i)