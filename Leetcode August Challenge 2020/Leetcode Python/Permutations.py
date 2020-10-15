class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.dfs(nums,[],res)
        return res
    
    def dfs(self, nums,path,res):
        
        if len(nums) == 0:
            res.append(path)
            # return res
        
        for i in range(len(nums)):
            self.dfs(nums[:i] + nums[i+1:], path+[nums[i]], res)
        
