class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        length=len(s)
        for i in range(length//2):
            substring=s[:i+1]
            if(substring*(length//(len(substring)))==s):
                return True
        return False