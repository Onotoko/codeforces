"""https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895"""
from queue import PriorityQueue

"""
	The idea:
		- To build a min heap => O(logN)
		- To calculate cost by
			Loop when size of heap > 1:
			+ Get first operand from the top of heap and remove it from heap
			+ Get second operand from the top of heap and remove it from heap
			=> cost = first operand + second operand
			+ Push cost into heap
			+ Calculate total cost
		=> O(logN)
	The complexity:
		O(logN)

"""
if __name__=="__main__":
	while (1):
		q = PriorityQueue()
		A = []
		cost = 0
		total_cost = 0
		# Read data
		n = int(input())
		if n == 0 :
			break
		A = list(map(int,input().split()))
		# Build a min heap
		for i in range(n):
			q.put(A[i])
		# Calculate cost & total cost
		while len(q.queue) > 1:
			cost = q.get()
			cost += q.get()
			total_cost+=cost
			q.put(cost)
		print(total_cost)
