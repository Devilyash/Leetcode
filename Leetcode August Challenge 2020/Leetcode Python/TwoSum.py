from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                sum=nums[i]+nums[j]
                if sum==target:
                    return[i,j]
                j=j+1
            i=i+1

obj = Solution()
print(obj.twoSum([2,7,15,19],9))
