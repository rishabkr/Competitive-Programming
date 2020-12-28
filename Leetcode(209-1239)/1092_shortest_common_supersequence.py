class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        def get_scs(str1,str2):
            m=len(str1)
            n=len(str2)
            lcs=[[0 for _ in range(0,n+1)] for _ in range(0,m+1)]
            for i in range(0,len(str1)+1):
                for j in range(0,len(str2)+1):
                    if(i==0 or j==0):
                        lcs[i][j]=0
                    elif(str1[i-1]==str2[j-1]):
                        lcs[i][j]=1+lcs[i-1][j-1]
                    else:
                        lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1])
                    
            #answer is str1+str2-lcs(str1,str2)
            
            i=m
            j=n
            res=""
            while(i>0 and j>0):
                if(str1[i-1]==str2[j-1]):
                    res+=str1[i-1]
                    i-=1
                    j-=1
                else:
                    if(lcs[i][j-1]>lcs[i-1][j]):
                        res+=str2[j-1]
                        j-=1
                    else:
                        res+=str1[i-1]
                        i-=1
            while(i>0):
                    res+=str1[i-1]
                    i-=1
            while(j>0):
                    res+=str2[j-1]
                    j-=1
            return res[::-1]
            
        return get_scs(str1,str2)