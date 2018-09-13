"""http://algote.com/team/problem_v1.php?id=214"""
INF = int(1e9)

class Edge:
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
	T = int(input())
	cnt = 0
	while T:
		line = ''
		while line == '':
			line = input().strip()
		cnt +=1
		n = int(line)
		B = list(map(int, input().strip().split()))
		m = int(input())
		graph = []
		dist = [INF for _ in range(n+1)]
		for i in range(m):
			u,v = list(map(int, input().strip().split()))
			w = (B[v-1] - B[u-1])**3
			graph.append(Edge(u,v,w))
		res = Bellman_Ford(1,n,m,graph,dist)
		q = int(input())
		print("Case {0}:".format(cnt))
		for _ in range(q):
			d = int(input())
			cost = dist[d]
			if cost < 3 or cost == INF or not res:
				print("?")
			else:
				print(cost)
		T -= 1