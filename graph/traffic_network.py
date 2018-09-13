"""https://www.spoj.com/problems/TRAFFICN/en/"""
from queue import PriorityQueue

INF = int(1e9)

class Node:
	def __init__(self, id, cost):
		self.id = id
		self.cost = cost
	def __lt__(self, other):
		return self.cost <= other.cost

def Dijsktra(s):
	pq = PriorityQueue()
	pq.put(Node(s,0))
	dist[s] = 0

	while(not pq.empty()):
		node = pq.get()
		u = node.id
		w = node.cost

		# if u == e:
		# 	break
		for v in graph[u]:
			if dist[v.id] > w + v.cost:
				dist[v.id] = w + v.cost
				pq.put(Node(v.id, dist[v.id]))
	return dist[e]
#To see file traffic_network.cpp
if __name__ == "__main__":

	tc = int(input())
	while tc:
		n,m,k,s,t = list(map(int, input().strip().split(' ')))
		graph = [[] for _ in range(n+1)]
		dist = [INF for _ in range(n+1)]
		for i in range(m):
			u,v,w = list(map(int, input().strip().split(' ')))
			graph[u].append(Node(v,w))
		for i in range(k):
			u,v,w = list(map(int, input().strip().split(' ')))
			graph[u].append(Node(v,w))
			graph[v].append(Node(u,w))
		print(Dijsktra(s))
		tc -=1