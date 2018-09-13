from queue import Queue

"""
	The idea:
		- Read all keys into a list (keys)
		- The first we push Sampit's key into queue, then we use BFS
		  to find lock key.
		  + which level in BFS we pop key in queue then multiple them 
		  	with each elememt in list of keys
		  + Note: We should check the value which exits or not
	The complexity:
		- Each level we have (N) operator except level 0 we have N operator
		-> The complexity O(level*N)
"""
samapit_key, lock_key = map(int, input().split())
n = int(input())
keys = list(map(int, input().split()))

q = Queue()
q.put(samapit_key)
vistied = [0 for _ in range (100001)]
vistied[samapit_key] = 0
#using BFS
while(not q.empty()):
	key = q.get()
	if(key == lock_key):
		print(vistied[key])
		exit(0)
	for i in range(n):
		check = (key * keys[i]) % 100000
		if(vistied[check] == 0):
			q.put(check)
			vistied[check] = vistied[key] + 1
print(-1)