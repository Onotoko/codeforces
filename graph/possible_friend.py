"""https://www.spoj.com/problems/SOCIALNE/"""

INF = int(1e9)
def Floyd(n,dist, path):
	for k in range(n):
		for i in range(n):
			for j in range(n):
				if dist[i][j] > dist[i][k] + dist[k][j]:
					dist[i][j] = dist[i][k] + dist[k][j]
					path[i][j] = path[k][j]
	for i in range(n):
		if dist[i][i] < 0:
			return False
	return True

if __name__ == "__main__":
	T = int(input())
	while T:
		idx = 0
		max_fr = 0
		data = input()
		V = len(data)
		dist = [[None for i in range(V)] for j in range(V) ]
		graph = [[None for i in range(V)] for j in range(V)]
		path = [[None for i in range(V)] for j in range(V)]
		for j in range(V):
			graph[0][j] = INF if data[j] == 'N' and j!=0 else 1
		for i in range(1,V):
			line = input()
			for j in range(V):
				graph[i][j] = INF if line[j] == 'N' and i!=j else 1

		#Prepare path for Floyd algorithm
		for i in range(V):
			for j in range(V):
				dist[i][j] = graph[i][j]
				if graph[i][j] !=INF and i != j:
					path[i][j] = i
				else:
					path[i][j] = -1
		Floyd(V,dist,path)
		for i in range(V):
			cnt = 0
			for j in range(V):
				if dist[i][j] == 2:
					cnt +=1
			if max_fr < cnt:
				max_fr = cnt
				idx = i
		print(idx,max_fr)
		T -=1