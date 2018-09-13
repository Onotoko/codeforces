"""https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498"""

"""
	The idea: Using Bellman-Ford  algorithms for this problems and add a condition into it:
			  if the value of curent source out of range (-100,100) we return False
	The complexity:
			- Read input & build graph: O(N)
			- Using BF: O(N^2)
			-> Complexity: O(N^2)
"""
INF = int(1e9)
class Edge:
	def __init__(self, source, dest, cost):
		self.source = source
		self.dest   = dest
		self.cost   = cost

def Bellman_Ford(s, nb_vertices, nb_edges,dist, graph):
	dist[s] = 0
	cost  = 100
	for i in range (1,nb_vertices):
		for j in range(nb_edges):
			u = graph[j].source
			v = graph[j].dest
			w = graph[j].cost
			if dist[u] != INF and dist[u] + w < dist[v]: 
				dist[v] = dist[u] + w
				cost += w
			if v == nb_vertices:
				return True
	if cost <= 0:
		return False
	for i in range(nb_edges):
		u = graph[i].source
		v = graph[i].dest
		w = graph[i].cost
		if dist[u]!=INF and dist[u] + w < dist[v]:
			return False

	return True

if __name__ == "__main__":
	cnt = 0
	while 1:
		cnt+=1
		graph = []
		line = input().strip()
		while line == '':
			line = input()
		n = int(line)
		m = 0
		if n == -1:
			break
		for i in range(1,n+1):
			edge = list(map(int, input().split()))
			m += edge[1]
			if edge[1] > 0:
				for j in range(2,len(edge)):
					graph.append(Edge(i,edge[j],edge[0]))
			else:
				graph.append(Edge(i,i,edge[0]))
		dist = [INF for _ in range(101)]
		res = Bellman_Ford(1,n,m,dist,graph)
		if res:
			print("winnable")
		else:
			print("hopeless")
