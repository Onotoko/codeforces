"""https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146"""
from queue import Queue, PriorityQueue

class PQEntry:
	def __init__(self, value):
		self.value = value
	def __lt__(self, other):
		return self.value > other.value

if __name__ =="__main__":
	while (1):
		# Init data
		s = []
		q = Queue()
		pq = PriorityQueue()
		cnt_stack = 0
		cnt_queue = 0
		cnt_priority_queue = 0
		# Read data
		n = int(input())
		for _ in range(n):
			command = list(map(int, input().strip().split(' ')))
			if command[0] == 1:
				s.append(command[1])
				q.put(command[1])
				pq.put(PQEntry(command[1]))
				cnt_stack +=1
				cnt_queue +=1
				cnt_priority_queue +=1
			if command[0] == 2:
				if len(s) > 0  and command[1] == s.pop():
					cnt_stack -=1
					# is_queue = False
				if not q.empty() and command[1] == q.get():
					cnt_queue -=1
				if len(pq.queue) > 0 and command[1] == pq.get().value:
					cnt_priority_queue-=1
		print(cnt_stack, cnt_queue, cnt_priority_queue)
		if cnt_stack > 0 and cnt_queue > 0 and cnt_priority_queue > 0:
			print("impossible")
		elif cnt_stack == 0 and cnt_queue > 0 and cnt_priority_queue > 0:
			print("stack")
		elif cnt_queue == 0 and cnt_priority_queue > 0 and cnt_stack > 0:
			print("queue")
		elif cnt_priority_queue == 0 and cnt_queue > 0 and cnt_stack > 0:
			print("priority queue")
		else:
			print("not sure")
