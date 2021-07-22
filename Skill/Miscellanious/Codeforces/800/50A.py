m, n = map(int, input().split())
ans = 0
if m & 1 and n & 1:
    ans = (m - 1) * (n - 1) / 2 + n // 2 + m // 2
elif m & 1 and not (n & 1):
    ans = (m - 1) * n / 2 + n / 2
elif not (m & 1) and n & 1:
    ans = (n - 1) * m / 2 + m / 2
else :
    ans = n * m / 2

print(ans)