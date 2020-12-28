string=input()

prefix_arr=[]
suffix_arr=[]

n=len(string)


prefix_arr=[string[:k+1] for k in range(n)]

suffix_arr=[string[-k-1:] for k in range(n)]

for i in range(n):
	if(prefix_arr[i]==suffix_arr[i] and prefix_arr[i]!=string):
		print(len(prefix_arr[i]))