import common, heapq, math



def compute(N):
    isprime = common.list_primality(N)

    d = [None]*(N + 1)
    d[2] = 2
    queue = [(2, 2)]
    while len(queue) > 0:
        dmax, u = heapq.heappop(queue)
        digit_rep = get_digit_rep(u)
        temp_digit_rep = list(digit_rep)
        for i in range(len(digit_rep)):
            for j in range(10):
                temp_digit_rep[i] = j
                v = to_number(temp_digit_rep)
                if  v >= len(isprime) or (v < len(isprime) and not isprime[v]):
                    continue
                dvmax = max(d[u], v)
                if d[v] is None or (d[v] is not None and dvmax < d[v]):
                    d[v] = dvmax 
                    heapq.heappush(queue, (dvmax, v))
            temp_digit_rep[i] = digit_rep[i]
    ans = 0
    for i in range(2, N + 1):
        if isprime[i] and ((d[i] is None) or (d[i] > i)):
            # print(i, d[i])
            ans += i
    return ans


def get_digit_rep(N):
    ans = []
    while N > 0:
        ans.insert(0, N % 10)
        N //= 10
    ans.insert(0, 0)
    return ans 

def to_number(digit_rep):
    ans = 0
    for dig in digit_rep:
        ans = ans * 10 + dig 
    return ans 


N = int(input())
print(compute(N))
