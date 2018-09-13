#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
	Ý tưởng của bài toán:(Sử dụng queue vòng) 
	- Step 1: Sử dụng queue để lấy thứ tự của các công dân(lấy min của p và c,
	 vì tối đa duyệt qua c command)
	- Step 2: Lặp qua các command
		+ Step 2.1: Nếu command là 'N'-> lấy phần tử đầu tiên trong queue
		 và đưa vào mảng kết quả(processed), và đẩy phần tử này vào cuối queue
		 + Step 2.1: Nếu commnad là 'E'-> Duyệt queue để tìm vị trí công dân có
		 số thứ tự bằng với x để xoá trong queue, sau đó thêm x lên đầu queue
	- Step 3: in ra kết quả

	Độ phức tạp của bài toán:
	- Step 1: O(k), k = min(p,c)
	- Step 2: 
	+ Duyệt qua c command: O(C)
	+ Duyệt queue khi command là E: O(k)
	->Worst case O(c*k)
	-> Độ phức tạp bài toán: O(k) + O(c*k) ~ O(c*k)
*/
int main()
{
	long int p, c;
	char n;
	long int x, temp;
	deque<long int> admited;
	vector<long int> processed;
	int cnt = 0;
	for(;;)
	{
		cin>>p>>c;
		if(p == 0 || c == 0)
			break;
		p = min(p,c);
		for(int i = 0 ; i < p ;i++)
		{
			admited.push_back(i+1);
		}
		for(int i= 0 ; i< c;i++)
		{
			cin>>n;
			if(n == 'N')
			{
 				temp = admited.front();
				processed.push_back(temp);
				admited.pop_front();
				admited.push_back(temp);
			}
			else if(n == 'E')
			{
				cin>>x;
				//Get element x out of queue
				for ( auto it = admited.begin(); it != admited.end(); ++it )
				{
					if(*it == x)
					{
						admited.erase(it);
						break;
					}	
				}
				admited.push_front(x);
			}
		}
		admited.clear();
		//Print output
		cout<<"Case "<<++cnt<<":\n";
		for(int i = 0; i < processed.size(); i++)
		{
			printf("%ld\n",processed[i]);
		}
		processed.clear();
	}
	return 0;
}