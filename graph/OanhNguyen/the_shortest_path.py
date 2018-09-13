"""https://www.spoj.com/problems/SHPATH/en/"""
from queue import PriorityQueue

INF = int(1e9)

"""
	The idea: Using Dijstra algroithm with min heap to deal this problems with some tricks:
			- Using dictionary to map name of city with id number
	The complexity:
			- Using dictionary to get id: O(n)
			- Using Dijstra: O(ElogN)
		->total T*(O(n) + O(NlogN))
"""
class City:
	def __init__(self, id, cost):
		self.id = id
		self.cost = cost
	def __lt__(self, other):
		return self.cost <= other.cost

def Dijkstra(start, end, dist, graph):
	pq = PriorityQueue()
	pq.put(City(start,0))
	dist[start] = 0
	while not pq.empty():
		c = pq.get()
		u = c.id
		w = c.cost
		if u == end:
			break
		for v in graph[u]:
			if dist[v.id] > w + v.cost:
				dist[v.id] = w + v.cost
				pq.put(City(v.id,dist[v.id]))
	return dist[end]

if __name__ == "__main__":
	test_case = int(input().strip())
	while test_case:
		num_cities = input()
		while num_cities == '':
			num_cities = input()
		num_cities = int(num_cities)
		graph = [[] for _ in range(num_cities + 1)]
		map_name_id = {}
		for i in range(1,num_cities+1):
			name_city = input()
			map_name_id[name_city] = i 
			connect = int(input())
			while connect:
				v,w = list(map(int, input().strip().split(' ')))
				graph[i].append(City(v,w) )
				connect -=1
		route = int(input())
		for _ in range(route):
			dist  = [INF for _ in range(num_cities + 1)]

			c1, c2 = map(str, input().strip().split())
			min_cost = Dijkstra(map_name_id[c1], map_name_id[c2],dist, graph)
			print(min_cost)
		test_case -=1

