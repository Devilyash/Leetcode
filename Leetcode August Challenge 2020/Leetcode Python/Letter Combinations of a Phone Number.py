class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        if digits == '':
            return
        
        dic = {
            '2' : 'abc',
            '3' : 'def',
            '4' : 'ghi',
            '5' : 'jkl',
            '6' : 'mno',
            '7' : 'pqrs',
            '8' : 'tuv',
            '9' : 'wxyz'
        }
        
        lst = [""]
        
        for i in digits:
            val = dic[i]
            newresult = []
            for char in val:
                for string in lst:
                    newresult.append(string+char)
            lst = newresult
        return lst

