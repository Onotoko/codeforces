from queue import Queue
def DFS(V, E, i):
	V[i] = True
	for v in E[i]:
		if not V[v]:
			DFS(V, E, v)

def BFS(s, E, V):
	q = Queue()
	q.put(s)
	V[s] = True
	while not q.empty():
	    u = q.get()
	    for v in E[u]:
	        if not V[v]:
	            V[v] = True
	            q.put(v)
if __name__ == "__main__":
    query = int(input())
    while query:
        lib  = 0
        n,m,clib, croad = list(map(int, input().strip().split()))

        if croad > clib:
            print(n*clib)
        else:
        	E = [[] for _ in range(n+1)]
        	V = [False for _ in range(n+1)]
        	for _ in range(m):
	            u,v = list(map(int, input().strip().split()))
	            E[u].append(v)
	            E[v].append(u)
	        for i in range(1,n+1):
	        	if not V[i]:
	        		DFS(V,E,i)
	        		lib+= 1
	        print(lib*clib + (n-lib)*croad)
        query -= 1
