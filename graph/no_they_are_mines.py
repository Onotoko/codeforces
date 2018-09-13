
from queue import PriorityQueue

INF = int(1e9)
dx = [0,0,1,-1]
dy = [1,-1,0,0]
class Mines:
 	def __init__(self, id, time):
 		self.id = id
 		self.time 	= time
 	def __lt__(self, other):
 		return self.time <= other.time

def Dijkstra(s,d,n,m):
	pq = PriorityQueue()
	pq.put(Mines(s,0))
	dist[s[0]][s[1]] = 0

	while not pq.empty():
		mine = pq.get()
		u = mine.id
		w = mine.time
		if u[0] == d[0] and u[1] == d[1]:
			break
		for k in range(4):
			kx = u[0] + dx[k]
			ky = u[1] + dy[k]
			if (kx >=0 and kx < n) and (ky >=0 and ky < m) and M[kx][ky] == 1:
				if w + 1 < dist[kx][ky]:
					dist[kx][ky] = w + 1
					pq.put(Mines([kx,ky],dist[kx][ky]))
	return dist[d[0]][d[1]]

if __name__ == "__main__":
	
	while 1:
		R , C = list(map(int, input().split()))
		if R == 0 and C == 0:
			break;
		M = [[1 for _ in range(C)] for _ in range(R)]
		dist = [[INF for _ in range(C)] for _ in range(R)]
		r = int(input())
		for _ in range(r):
			rows = list(map(int, input().split()))
			for i in range(2,len(rows)):
				M[rows[0]][rows[i]] = 0
		s_r,s_c= list(map(int, input().split()))
		d_r,d_c=list(map(int, input().split()))
		cost = Dijkstra([s_r,s_c],[d_r,d_c],R,C)
		print(cost)
	