class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper():
            return True
        elif word.islower():
            return True
        else:
            lst = []
            lst.append(word[:1])
            lst.append(word[1:])
            if lst[0].isupper() and lst[1].islower():
                return True
            else:
                return False

obj = Solution()
word = input()
print(obj.detectCapitalUse(word))
