"""https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927"""

from queue import PriorityQueue

INF = int(1e9)

"""
	The idea: using Dijsktra to deal this problems with each smtp server likes a vertex in graph
	The complexity: T*O(NLog(N))
"""
class SMTP:
 	def __init__(self, id, time):
 		self.id = id
 		self.time 	= time
 	def __lt__(self, other):
 		return self.time <= other.time

def Dijkstra(s,d):
	pq = PriorityQueue()
	pq.put(SMTP(s,0))
	dist[s] = 0

	while not pq.empty():
		smtp = pq.get()
		u = smtp.id
		w = smtp.time
		for v in graph[u]:
			if w + v.time < dist[v.id]:
				dist[v.id] = w + v.time
				pq.put(SMTP(v.id,dist[v.id]))
	return dist[d]

if __name__ == "__main__":
	test_cases = int(input())
	cnt = 1
	while test_cases:
		n,m,s,t = list(map(int, input().split(' ')))
		graph = [[] for _ in range(n)]
		dist  = [INF for _ in range(n)]
		for _ in range(m):
			u,v,w = list(map(int, input().split(' ')))
			graph[u].append(SMTP(v,w))
			graph[v].append(SMTP(u,w))
		min_time = Dijkstra(s,t)
		if min_time == INF:
			print("Case #{}: unreachable".format(cnt))
		else:
			print("Case #{0}: {1}".format(cnt,min_time))
		cnt +=1
		test_cases -=1

