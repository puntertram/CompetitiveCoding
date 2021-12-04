from collections import defaultdict
class Solution:
    # calculate arr : arr_j contains the smallest prime factor of j
    M = 10**5 + 5
    arr = [0]*(M + 1)
    for i in range(2, M + 1):
        for j in range(i, M + 1, i):
            if arr[j] == 0:
                arr[j] = i 
    
    def factorize(self, num):
        primes = set()
        while self.arr[num] != 0:
            primes.add(self.arr[num])
            num //= self.arr[num]
        return primes 

    def gcdSort(self, nums):
        d = defaultdict(list)
        for i, num in enumerate(nums):
            for p in self.factorize(num):
                d[p].append(i)
        
        G = defaultdict(list)
        for l in d.values():
            for u, v in zip(l, l[1:]):
                G[u].append(v)
                G[v].append(u)
        visited = [0]*(len(nums))
        comp = 1
        connected_components = defaultdict(list)
        
        def dfs(u, i):
            visited[u] = i 
            connected_components[i].append(u)
            for v in G[u]:
                if visited[v] == 0:
                    dfs(v, i)
        
        for i in range(len(nums)):
            if visited[i] == 0:
                dfs(i, comp)
                comp += 1
        ans = [0]*(len(nums))

        for c in connected_components.values():
            for i, v in zip(sorted(c), sorted(nums[t] for t in c)): 
                ans[i] = v 
        
        return (ans == sorted(nums))

s = Solution()
print(s.gcdSort([10,5,9,3,15]))