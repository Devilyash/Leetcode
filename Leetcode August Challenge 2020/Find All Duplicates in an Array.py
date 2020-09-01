class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for n in nums:
            value =  abs(n)
            index = value-1
            if nums[index] < 0:
                res.append(value)
            nums[index] *= -1
        return res

obj = Solution()
s = list(map(int, input().split()))
print(obj.findDuplicates(s))
