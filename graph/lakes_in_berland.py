"""
	The idea:
	The complexity:
"""

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def DFS_border(Edges, visited):
	stack = []
	for i in range(0,n):
		for j in range(0,m):
			if (Edges[i][j] == '.') and (i == 0 or j == 0 or i == n-1 or j == m-1) and (visited[i][j] == 0):
				stack.append([i,j])
				visited[i][j] = 1
				while(len(stack) > 0):
					cell = stack[-1]
					stack.pop()
					for k in range(4):
						kx = cell[0] + dx[k]
						ky = cell[1] + dy[k]
						if (kx >=0 and kx < n) and (ky >=0 and ky <m):
							if (visited[kx][ky] == 0) and (Edges[kx][ky] == '.'):
								stack.append([kx,ky])
								visited[kx][ky] = 1

def DFS(n,m, Edges):
	L = [] #Lakes
	stack = []
	visited = [[0 for _ in range(m)] for _ in range(n)]
	DFS_border(Edges, visited)
	for i in range(1,n-1):
		for j in range(1,m-1):
			cnt = 0
			land_cells = []
			if Edges[i][j] == '.' and visited[i][j] == 0:
				visited[i][j] = 1
				stack.append([i,j])
				land_cells.append([i,j])
				cnt +=1
				while(len(stack) > 0):
					cell = stack[-1]
					stack.pop()
					for k in range(4):
						kx = cell[0] + dx[k]
						ky = cell[1] + dy[k]
						if (kx >=1 and kx < n-1) and (ky >=1 and ky < m-1):
							if (visited[kx][ky] == 0) and (Edges[kx][ky] == '.'):
								stack.append([kx,ky])
								land_cells.append([kx,ky])
								visited[kx][ky] = 1
								cnt+=1
				land_cells.append(cnt)
				L.append(land_cells)
	return L

if __name__ == '__main__':
	M = [] #Map
	# Read input
	n, m, k = map(int, input().split())
	for i in range(n):
		M.append([j for j in input()])
	#Find lakes
	lakes = DFS(n,m,M)
	#Sort result
	lakes.sort(key = lambda x:x[-1],reverse=True)
	#Calculate and print output
	num_water_cells = 0
	while len(lakes) != k:
		land_cell = lakes[-1]
		num_water_cells += land_cell[-1]
		lakes.pop()
		for i in range(len(land_cell) - 1):
			mod_cell = land_cell[i]
			M[mod_cell[0]][mod_cell[1]] = '*'
	print(num_water_cells)
	for i in range(n):
		for j in range(m):
			print(M[i][j],end='')
		print()








	
