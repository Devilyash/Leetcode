class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.dfs(nums, 0, [], res)
        return res
    
    def dfs(self, nums, index, path, res):
        if  nums == []:
            res.append([])
        print('res: ', res)
        for i in range(index,len(nums)):
            print('index: ',index)
            self.dfs(nums, i+1, path + [nums[i]], res)
              
