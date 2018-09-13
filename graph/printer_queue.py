

class PQEntry:
    def __init__(self, priority = 0):
        self.priority = priority
    def __lt__(self, other):
        return self.priority > other.priority
if __name__ =="__main__":
	tc = int(input())
	while tc:
		cost = 0
		idx = 0
		q = []
		n,m = list(map(int, input().split()))
		val = list(map(int, input().split()))
		my_job = val[m]
		for i in range(n):
			if i == m:
				q.append([val[i],1])
			else:
				q.append([val[i],0])
		while True:
			done = True
			j = q.pop(0)
			for i in range(len(q)):
				if j[0] < q[i][0]:
					q.append(j)
					done = False
					break
			if done:
				cost += 1
				if j[1]:
					break

		print(cost)
		tc -=1
