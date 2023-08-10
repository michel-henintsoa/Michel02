n=4
n+=1
k=n
#tab=[][]
for i in range(n):
	print(" "*k,end="")
	print("*"*(2*i-1))
	k-=1
k=n-1
for i in range(1,n):
	print(" "*(i+1),end="")
	print("*"*(2*k-3))
	k-=1
k=n
for i in range(n):
	print(" "*n," "*i,"*"*k)
	k-=1


