"""https://www.spoj.com/problems/MICEMAZE/"""
from queue import PriorityQueue
 
INF = int(1e9)
class Node:
	def __init__(self, id, cost):
		self.id = id
		self.cost = cost
	def __lt__(self, other):
		return self.cost <= other.cost
 
def Dijsktra(s, d):
	pq = PriorityQueue()
	pq.put(Node(s,0))
	dist[s] = 0
	while not pq.empty():
		node = pq.get()
		u = node.id
		w = node.cost
 
		for i in graph[u]:
			if w + i.cost < dist[i.id]:
				dist[i.id] = w + i.cost
				pq.put(Node(i.id, dist[i.id]))
 
	return dist[d]
 
if __name__ == "__main__":
 
	mice = []
	cnt = 0
	n = int(input())
	exit = int(input())
	time = int(input())
	m = int(input())
	graph = [[] for _ in range(n+1)]
	# path  = [-1 in range(n+1)]
	for i in range(m):
		v1,v2,w = list(map(int, input().strip().split(' ')))
		graph[v1].append(Node(v2, w))
 
	# Calculate Dijsktra
	for i in range(1,n+1):
		dist  = [INF for _ in range(n+1)]
		mice.append(Dijsktra(i,exit))
 
	# Sort mice
	mice.sort(reverse = True)
	while  time:
		while mice[-1] <= time:
			cnt+=1
			mice.pop()
		time -=1
 
	print(cnt)