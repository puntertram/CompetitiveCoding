from math import gcd
def solve():
    L, N = map(int, input().split())
    arr = list(map(int, input().split()))
    P = [0]*(L + 1)
    for i in range(len(arr) - 1):
        A = arr[i]
        B = arr[i + 1]
        C = gcd(A, B)
        P[i] = int(A / C)
        P[i + 2] = int(B / C)
    print(P)
T = int(input())
while T > 0:
    solve()
    T -= 1