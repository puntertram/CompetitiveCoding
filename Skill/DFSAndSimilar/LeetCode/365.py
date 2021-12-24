class Solution:
    def canMeasureWater(self, A: int, B: int, C: int) -> bool:
        if A > B:
            A, B = B, A 
        
        if C > A + B:
            return False

        queue = [(0, 0)]
        visited = set((0, 0))

        while len(queue) > 0:
            a, b = queue.pop(0)
            if a + b == C:
                return True 
            states = set() 
            states.add((A, b))
            states.add((a, B))
            states.add((0, b))
            states.add((a, 0))
            states.add((a - (min(B, b + a) - b), b + (min(B, b + a) - b)))
            states.add((a + (min(A, a + B) - a), b - (min(A, a + b) - a)))
            
            for state in states:
                if state in visited:
                    continue 
                queue.append(state)
                visited.add(state)
        return False 

if __name__ == "__main__":
    S = Solution() 
    print(S.canMeasureWater(3, 4, 2))