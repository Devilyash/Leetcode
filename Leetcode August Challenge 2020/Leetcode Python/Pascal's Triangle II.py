class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]*(rowIndex+1)
        for i in range(1,rowIndex):
            for j in range(i,0,-1):
                print(j)
                res[j] += res[j-1]
                print(res)
        return res
        
obj = Solution()
num = int(input())
print(obj.getRow(num))
#11**0 = 0
#11**1 = 11
#11**2 == 121
#11**3 = 1331
