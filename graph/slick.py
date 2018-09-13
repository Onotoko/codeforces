"https://www.spoj.com/problems/UCV2013H/"
from queue import Queue

dx = [0,0,1,-1]
dy = [1,-1,0,0]


while(1):
	n,m = map(int, input().split())
	if n == 0 and m == 0:
		break
	#Read data
	cnt = 0
	slick = 0
	q = Queue()
	V = []
	S = []
	R = {}
	for i in range(0, n):
		S.append(list(map(int, input().split())))
		V.append([False for _ in range(m)])
	#Find all slicks
	for i in range(n):
		for j in range(m):
			slick = 0
			if S[i][j] == 1 and V[i][j] == False:
				#Using BFS
				q.put([i,j])
				slick +=1
				V[i][j] = True
				while(not q.empty()):
					v = q.get()
					# print(V)
					for k in range(4):
						kx = v[0] + dx[k]
						ky = v[1] + dy[k]
						if(kx>=0 and kx < n) and(ky >=0 and ky < m):
						    if V[kx][ky] == False and S[kx][ky] == 1:
						    	q.put([kx,ky])
						    	V[kx][ky] = True
						    	slick+=1
				if R.get(slick) != None:
					R[slick]+=1
				else:
					R[slick] =1
				cnt+=1
	slicks = sorted(R.items(), key=lambda x: x[0])
	print(cnt)
	for i in range(len(slicks)):
		print(slicks[i][0], slicks[i][1])	


