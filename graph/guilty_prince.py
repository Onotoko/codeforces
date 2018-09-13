from queue import Queue
"""
	The idea:
		- Read data into a matrix which has shape [h+2, w+2] (added padding to all border)
		- Build a graph with (h+2)*(w+2) nodes
		- Build a list edges. Two points (i,j) and (i,j+1) it called edges if (i,j) = '.'
		  and (i,j+1) = '.'
		- Remember store position of start '@'
		- Using BFS algorithm to found path for prince
	The complexity:
		- Read data: O(h)
		- Build edges: O(h*w)
		- Using BFS: O((w*h) + (w*h)*4) ~ O(w*h)(because each of vertex we have almost 4 edges)
		-> The complexity: O(w*h)
"""
q = Queue()
T = int(input())
cnt = 0
while cnt < T :
	cnt+=1
	w, h = map(int, input().split())
	h = h+2
	w = w+2
	visited = [False for _ in range(h*w)]
	edges = [[-1] for _ in range(h*w)]
	matrix = []
	start = 0
	tol_cells = 0
	#Read data
	matrix.append('#'* w)
	for _ in range(1,h-1):
		matrix.append('#' + input() + '#')
	matrix.append('#'*w)
	#Build edges
	for i in range(1,h-1):
		for j in range(1,w-1):
			vertex = []
			if matrix[i][j] == '.' or matrix[i][j] == '@':
				if matrix[i][j+1] == '.':
					vertex.append(i*w + (j+1))
				if matrix[i][j-1] == '.':
					vertex.append(i*w + (j-1))
				if matrix[i+1][j] == '.':
					vertex.append((i+1)*w + j)
				if matrix[i-1][j] == '.':
					vertex.append((i-1)*w + j)
				edges[i*w + j] = vertex
			if matrix[i][j] == '@':
				start = i*w + j
	#Using BFS algorithm to find total cells
	q.put(start)
	visited[start] = True
	tol_cells += 1
	while( not q.empty()):
		start = q.get()
		edge = edges[start]
		for i in range(len(edge)):
			if(visited[edge[i]] == False):
				visited[edge[i]] = True
				q.put(edge[i])
				tol_cells+=1
	print("Case {0}: {1}".format(cnt,tol_cells))