""" https://www.codechef.com/problems/RRATING """
from queue import PriorityQueue
import heapq
import math
"""
"""
class PQEntry:
    def __init__(self, value):
        self.value = value
    def __lt__(self, other):
        return self.value > other.value
def heapify(h,n,i):
	largest = i
	l = i*2 + 1
	r = i*2 + 2 
	if l < n and h[l] < h[largest]:
		largest = l
	if r < n and h[r] < h[largest]:
		largest = r
	if largest != i:
		h[i],h[largest] = h[largest],h[i]
		heapify(h,n,largest) 
def put(h,val):
    h.append(val)
    i = len(h) - 1
    while i!=0 and h[(i-1)//2] > h[i]:
        h[i],h[(i-1)//2] = h[(i-1)//2], h[i]
        i = (i-1)//2
def buidHeap(h):
	n = len(h)
	for i in range(n//2,-1,-1):
		heapify(h,n,i)
def heapSort(h):
	n = len(h)
	for i in range(n-1,0,-1):
		h[i],h[0] = h[0],h[i]
		heapify(h,i,0)
	return h
# if __name__ == "__main__":
# 	q = PriorityQueue()
# 	h =[]
# 	cnt_add = 0
# 	n = int(input())
# 	for _ in range(n):
# 		cmd = list(map(int,input().strip().split(' ')))
# 		if cmd[0] == 1:
# 			# q.put(PQEntry(cmd[1]))
# 			h.append(cmd[1])
# 			cnt_add += 1
# 		elif cmd[0] == 2:
# 			if cnt_add <=2 :
# 				print("No reviews yet")
# 			else:
# 				h = heapSort(h)
# 				# q.queue = heapSort(q.queue)
# 				nb_ratings = math.floor(cnt_add/3)
# 				if nb_ratings == 1:
# 					print(h[0])
# 				elif nb_ratings == 2:
# 					print(h[1])
# 				else:
# 					print(h[2])
if __name__ == "__main__":
	min_heap = []#PriorityQueue()
	max_heap = []#PriorityQueue()
	cnt_add = 0
	n = int(input())
	for _ in range(n):
		cmd = list(map(int,input().strip().split(' ')))
		if cmd[0] == 1:
			cnt_add += 1
			heapq.heappush(max_heap, -cmd[1])
			# max_heap.put(PQEntry(cmd[1]))
		else:
			if cnt_add <=2:
				print("No reviews yet")
			else:
				nb_ratings = math.floor(cnt_add/3)
				if nb_ratings == 1:
					# rat = max_heap.queue[0].value
					# min_heap.put(rat)
					rat = max_heap[0]
					heapq.heappush(min_heap, -rat)
				elif nb_ratings == 2:
					val = heapq.heappop(max_heap)
					rat = max_heap[0]
					heapq.heappush(min_heap, -rat)
					heapq.heappush(max_heap, val)
					# min_heap.put(rat)
					# max_heap.put(PQEntry(val))
				else:
					val1 = heapq.heappop(max_heap)
					val2 = heapq.heappop(max_heap)
					rat = max_heap[0]
					# max_heap.put(PQEntry(val1))
					# max_heap.put(PQEntry(val2))
					heapq.heappush(max_heap, val1)
					heapq.heappush(max_heap, val2)
					heapq.heappush(min_heap, -rat)
				print(min_heap[0])
