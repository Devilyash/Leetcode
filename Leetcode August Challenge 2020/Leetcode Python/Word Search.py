class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if len(board) == 0 or len(board[0]) == 0:
            return True
        
        row = len(board)
        col = len(board[0])
        
        for i in range(row):
            for j in range(col):
                if word[0] == board[i][j] and self.dfs(board,word,0,i,j):
                    return True
        return False
    
    def dfs(self,board,word,index,i,j):
        if len(word) == index:
            return True
        
        if i<0 or i>len(board)-1 or j<0 or j>len(board[0])-1 or board[i][j]!=word[index]:
            return False
        
        original = board[i][j]
        board[i][j] = ""
        
        if self.dfs(board,word,index+1,i-1,j) or self.dfs(board,word,index+1,i+1,j) or self.dfs(board,word,index+1,i,j-1) or self.dfs(board,word,index+1,i,j+1):
            return True
        else:
            board[i][j] = original
        

