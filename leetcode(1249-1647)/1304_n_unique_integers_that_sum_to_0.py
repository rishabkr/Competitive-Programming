class Solution:
    def sumZero(self, n: int) -> List[int]:
        lst=list(range(-int(n/2),int(n/2)+1))
        if(n%2==0):
            lst.remove(0)
        return lst