"""https://www.urionlinejudge.com.br/judge/en/problems/view/1655"""
"""
	The idea:
	The complexity:
"""
INF = int(1e9)
class Edge:
	def __init__(self,dest, cost):
		# self.source = source
		self.dest = dest
		self.cost = cost

# def Bellman_Ford(s,n,m,dist, graph):
# 	cost = 1
# 	idx = 1
# 	for i in range(1,n):
# 		max_p = 0
# 		i = idx
# 		for j in range(len(graph[i])):
# 			v = graph[i][j].dest
# 			w = graph[i][j].cost
# 			if max_p < w and dist[v] == INF:
# 				max_p = w
# 				idx = v
# 				dist[v] = w
# 		cost *= (0.01) * max_p
# 		if idx == n:
# 			break
# 	return cost
def Bellman_Ford(s, nb_vertices, nb_edges,dist, graph):
	dist[s] = 1
	for i in range (1,nb_vertices):
		for j in range(len(graph[i])):
			u = i
			v = graph[i][j].dest
			w = graph[i][j].cost
			if dist[u] != INF and dist[u]* w < dist[v]: 
				dist[v] = dist[u]*w*0.01

	return dist[nb_vertices]
if __name__ == "__main__":

	while 1:
		s = 0
		tc = list(map(int,input().split()))
		if tc[0] == 0:
			break
		n = tc[0]
		m = tc[1]
		graph = [[] for _ in range(n+1)]
		dist = [INF for _ in range(n+1)]

		for _ in range(m):
			edge = list(map(int, input().split()))
			graph[edge[0]].append(Edge(edge[1],-edge[2]))
			graph[edge[1]].append(Edge(edge[0],-edge[2]))

			# graph.append(Edge(edge[1],edge[0],-edge[2]))

		res = Bellman_Ford(1,n,m,dist,graph)
		print("{:.6f} percent".format(res*100))