#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
/*
	Ý tưởng của bài toán:
	- Gọi dãy các cố trà là V0, V2, ..., V(2n-1) và W là tổng số lít trà
	- Gọi y là số lít trà cho 1 bạn gái-> N*y là tổng số lít trà cho N bạn gái
	-> 2y là số lít trà cho 1 bạn trai -> 2*y*N là tổng số lít trà cho N bạn trai
	-> Vậy tổng số lít trà cho 2N trai và gái là 3*y*N
	- Tìm y:
	+ Do không được rót trà đầy quá thể tích mỗi cốc nước quy định, và trà được rót
	cho mỗi bạn gái là như nhau, mỗi bạn trai là như nhau, tổng số trà rót cho các
	bạn trai và gái lớn nhất có thể 
	-> Sắp xếp theo thứ tự tăng dần dãy 2N, N phần tử đầu tương ứng các cốc trà cho các
	bạn nữ, N phần tử tiếp theo tương ứng các cốc trà cho các bạn nam
	-> y = min(V0, V(2n-1)/2)
	-> tổng số lít trà cần tìm là: min(3*y*N,W)
	
*/
int main()
{
	long long int n, w;
	double y;
	//Read input
	cin>>n>>w;
	long long int a[2*n];
	for(int i = 0; i< 2*n;i++)
	{
		cin>>a[i];
	}
	//sort the capacities of Pasha's tea cups
	sort(a, a+(2*n));
	//calculate y 
	if(a[0]*2<= a[n])
		y = (double)a[0];
	else
		y = (double)a[n]/2.0;
	//print output
	if(3*y*n <= w)
		printf("%lf",(double)y*3*n);
	else
		cout<<w;
	return 0;
}