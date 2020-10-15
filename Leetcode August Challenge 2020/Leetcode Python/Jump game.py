class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        maxrange = 0
        for i in range(len(nums)):
            if i > maxrange:
                return False
            maxrange = max(maxrange, i+nums[i])
        return True
