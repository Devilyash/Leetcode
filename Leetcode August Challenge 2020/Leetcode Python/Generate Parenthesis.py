class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        self.dfs(n,n,"",ans)
        return ans
    
    def dfs(self, left, right, path, res):
        if right < left or left<0 or right<0:
            return
        
        if left==0 and right==0:
            res.append(path)
            return
        
        if left:
            self.dfs(left-1, right, path+"(", res)
        if right:
            self.dfs(left,right-1, path+")", res)
