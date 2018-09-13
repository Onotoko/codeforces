

if __name__ == "__main__":

	n = int(input())
	ar = list(map(int, input().split()))
	ar.sort()
	print(ar[len(ar)//2])

