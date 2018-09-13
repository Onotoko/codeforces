if __name__ == "__main__":
	A = [0 for _ in range(26)]
	n = int(input())
	s = input()
	for i in range(n):
		pos = 0
		if (ord(s[i]) >= 97 and ord(s[i]) <= 122):
			pos = ord(s[i]) - 97
		elif (ord(s[i]) >= 65 and ord(s[i]) <= 90):
			pos = ord(s[i]) - 65
		A[pos] +=1
		
	A.sort()
	if A[0] == 0:
		print("NO")
	else:
		print("YES")
