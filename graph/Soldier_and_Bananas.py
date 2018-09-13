
from queue import Queue
def BFS(k,s, E, V):
	cost = 0
	total = 0
	q = Queue()
	q.put(s)
	V[s] = True
	total += k
	while not q.empty():
	    u = q.get()
	    for v in E[u]:
	    	cost = v*k
	    	total += cost
	    	if not V[v]:
	            V[v] = True
	            q.put(v)
	return total

if __name__ == "__main__":
	cost = 0
	k,n,w = list(map(int, input().split()))
	E = [[] for _ in range(w+1)]
	V = [False for _ in range(w+1)]
	for i in range(1,w):
		E[i].append(i+1)
	#calculate cost
	cost = BFS(k,1,E,V)
	if cost <= n:
		print(0)
	else:
		print(cost-n)