"""https://www.spoj.com/problems/TRVCOST/"""
from queue import PriorityQueue

INF = int(1e9)

class Node:
	def __init__(self, id, dist):
		self.id = id
		self.dist = dist
	def __lt__(self, other):
		return self.dist <= other.dist

def Dijkstra(u):
	pq = PriorityQueue()
	pq.put(Node(u,0))
	dist[u] = 0

	while not pq.empty():
		top = pq.get()
		u = top.id
		w = top.dist

		for neighbor in graph[u]:
			if w + neighbor.dist < dist[neighbor.id]:
				dist[neighbor.id] = w + neighbor.dist
				pq.put(Node(neighbor.id, dist[neighbor.id]))
				path[neighbor.id] = u

if __name__ == "__main__":
	n = int(input())
	graph = [[] for _ in range(501)]
	dist = [INF for _ in range(501)]
	path = [-1 for _ in range(501)]

	for _ in range(n):
		v1,v2,w = list(map(int, input().strip().split(' ')))
		graph[v1].append(Node(v2,w))
		graph[v2].append(Node(v1,w))

	u = int(input())
	Dijkstra(u)
	q = int(input())
	for _ in range(q):
		qi = int(input())
		cost = dist[qi]
		if cost == INF:
			print("NO PATH")
		else:
			print(cost)

