import heapq

N = int(input())
A = list(map(int, input().split()))
h = [A[0],A[1],A[2]]

def MaxHeapify(i):
    largest = i
    left = i*2+1
    right = i*2+2
    if left < len(h) and h[left] > h[largest]:
        largest = left
    if right < len(h) and h[right] > h[largest]:
        largest = right
    if largest != i:
        h[i],h[largest] = h[largest],h[i]
        MaxHeapify(largest)
def buidHeap(n):
    for i in range((n//2)-1,-1,-1):
        MaxHeapify(i)
def push(element):
    h.append(element)
    i = len(h) - 1
    while i!=0 and h[(i-1)//2] < h[i]:
        h[i],h[(i-1)//2] = h[(i-1)//2], h[i]
        i = (i-1)//2

buidHeap(len(h))
print(-1)
print(-1)
print(A[0]*A[1]*A[2])
for i in range(3,N):
    #push tung phan tu vao heap -> xay dung max heap
    push(A[i])
    p = h[0]
    l = h[1]
    r = h[2]
    idx_l_l = 3
    idx_l_r = 4
    idx_r_l = 5
    idx_r_r = 6
    #If left less than right we move to right of tree
    if l < r:
        if idx_r_r < len(h) and idx_r_l < len(h):
            l = max(h[idx_r_r],h[idx_r_l],l)
        elif idx_r_r < len(h) and idx_r_l >=len(h):
            l = max(h[idx_r_r],l)
        elif idx_r_l < len(h) and idx_r_r>=len(h):
            l = max(h[idx_r_l],l)
    elif l > r:
        if idx_l_l < len(h) and idx_l_r < len(h):
            r = max(h[idx_l_l],h[idx_l_r],r)
        elif idx_l_l < len(h) and idx_l_r >=len(h):
            r = max(h[idx_l_l],r)
        elif idx_l_r < len(h) and idx_l_l>=len(h):
            r = max(h[idx_l_r],r)
    #Otherwies
    print(p*l*r)
    print(p, l,r)
    print(h)