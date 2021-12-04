from bisect import bisect
class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        def check(x):
            ret = 0
            for num in nums1:
                ret += bisect(nums2, x // num)
            return ret
        lo = nums1[0] * nums2[0], hi = nums1[-1] * nums2[-1]
        while lo <= hi:
            mid = (lo + hi) // 2
            v = check(mid) 
            if v == k:
                return mid 
            elif v > k:
                hi = mid - 1
            elif v < k:
                