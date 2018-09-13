"""https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499"""
INF = int(1e9)

class Edges:
	def __init__(self, source, dest, cost):
		self.source = source
		self.dest 	= dest
		self.cost 	= cost

def Bellman_Ford(s,n,m,graph, dist):
	dist[s] = 0
	for i in range(1,n):
		for j in range(m):
			u = graph[j].source
			v = graph[j].dest
			w = graph[j].cost

			if dist[u] != INF and dist[u] + w < dist[v]:
				dist[v] = dist[u] + w
	for i in range(m):
		u = graph[i].source
		v = graph[i].dest
		w = graph[i].cost

		if dist[u] != INF and dist[u] + w < dist[v]:
			return False
	return True

if __name__ == "__main__":
	c = int(input())
	while c:
		n, m = list(map(int, input().split()))
		graph = []
		dist = [INF for _ in range(n)]
		for _ in range(m):
			u,v,w = list(map(int, input().split()))
			graph.append(Edges(u,v,w))

		res = Bellman_Ford(0,n,m,graph,dist)
		if res:
			print("not possible")
		else:
			print("possible")
		c -= 1