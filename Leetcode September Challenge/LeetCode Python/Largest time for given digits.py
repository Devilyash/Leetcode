class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        m = -1
        for a,b,c,d in itertools.permutations(A):
            hour = a*10 + b
            minute = c*10 + d
            if hour< 24 and minute< 60:
                m = max(m, hour*60 + minute)
        if m == -1:
            return ""
        else:
            return "{:02d}:{:02d}".format(m//60, m%60)
        
