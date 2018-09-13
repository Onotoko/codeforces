"""https://www.urionlinejudge.com.br/judge/en/problems/view/1610"""

def DFS(u,Edges, visited):
	for v in Edges[u]:
		if visited[v] == 0 and DFS(v,Edges, visited) == True:
			return True
		elif visited[v] == 1:
			return True
	visited[u] = 2

	return False

if __name__ == "__main__":
	t = int(input())
	while t > 0:
		n, m = map(int, input().split())
		Edges = [[] for i in range(n+1)]
		for i in range(m):
			u,v = map(int, input().split())
			Edges[u].append(v)
		visited = [0 for _ in range(n+1)]
		for u in range(1,n+1):
			if(DFS(u, Edges, visited)):
				print("SIM")
			else:
				print("NAO")
		t -=1