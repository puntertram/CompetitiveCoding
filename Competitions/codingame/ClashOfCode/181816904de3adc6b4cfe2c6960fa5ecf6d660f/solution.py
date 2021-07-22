n = int(input())
ans = 0
for i in range(n):
    line = [*map(int, input().split())]
    # alternative
    for j in range(n):
        if i in [0,n-1] or j in [0,n - 1]:
            ans += line[j]

print(ans)
for i in range(n):
    line = [*map(int, input().split())]    
    if i in [0,n-1]:
        ans += sum(line)
        continue
    for j in range(n):
        if j in [0, n - 1]:
            ans += line[j]
print(ans)