#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int k,sum = 0;
	int a[12] = {0};
	//Read input data
	cin>>k;
	for(int i = 0; i < 12;i++)
	{
		cin>>a[i];
	}
	//Sort data
	if(k == 0)
	{
		cout<<0;
	}
	else
	{
		sort(a, a+12);
		for(int i = 11; i >= 0; i--)
		{
			sum += a[i];
			if(sum >=k)
			{
				cout<<12-i;
				return 0;
			}
		}
		cout<<-1;
    }
	return 0;
}