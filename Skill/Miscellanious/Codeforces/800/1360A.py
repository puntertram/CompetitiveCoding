t = int(input())
while t > 0:
    a, b = map(int, input().split())
    ans = min(max(a, 2 * b), max(b, 2 * a))
    print(ans**2)
    t -= 1