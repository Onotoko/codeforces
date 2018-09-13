"""https://www.spoj.com/problems/CAM5/"""
# Write your code here
def DFS(n, edges):
    cnt = 0
    visited = [0 for _ in range(n)]
    for i in range(n):
        if visited[i] == 0:   
            q = [i]
            visited[i] = 1
            while len(q) > 0:
                v = q[-1]
                q.pop()
                for u in edges[v]:
                    if  visited[u] == 0:
                        visited[u] = 1
                        q.append(u)
            cnt +=1
    return cnt
line = ''
while line == '':
    line = input()
t = int(line)
while(t > 0):
    line = ''
    while line == '':
        line = input()
    n = int(line)
    e = int(input())
    edges= [[] for _ in range(n)]
    for _ in range(e):
        u,v = map(int, input().split())
        edges[u].append(v)
        edges[v].append(u)

    p = DFS(n, edges)
    print(p)
    t -=1


