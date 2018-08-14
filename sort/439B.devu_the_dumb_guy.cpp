#include <iostream>
#include <algorithm>
using namespace std;
/*
	Ý tưởng của thuật toán:
	- Sắp xếp lại mảng (c)chứa các chương mà giáo viên sẽ dạu cho Devu
	  theo thứ tự tăng dần
	- Lặp to 0 tới n:
	  Tính tổng số phút nhỏ nhất theo công thức: ans = ans + c[i]*x
	  Nếu x > 1 thì giảm dần x
	- In kết quả
	- Độ phức tạp: O(nlogn) + O(n) = O(nlogn)
*/
int main()
{
	int  n,x,i;
	long long ans = 0;
	long long  c[100000] = {0};

	//Read input
	cin>>n>>x;
	for(i = 0; i< n;i++)
	{
		cin>>c[i];
	}

	//Sort c
	sort(c, c+n);

	//Calculate min time to teach
	for(i = 0; i < n; i++)
	{
		ans+= c[i]*x;
		if(x > 1)
		{
			x--;
		}
	}
	nlogn<ans;
	return 0;
}
