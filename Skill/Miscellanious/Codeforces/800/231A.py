N = int(input())
ans = 0
while N > 0:
    a, b, c = map(int, input().split())
    if a + b + c >= 2:
        ans += 1
    N -= 1
print(ans)