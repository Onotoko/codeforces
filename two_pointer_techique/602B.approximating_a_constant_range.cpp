#include <iostream>
using namespace std;
int main()
{
	int n,l = 0,max_length = 1,diff = 0;
	int arr[100001] = {0};
	int cnt[100001] = {0};
	//Read input
	cin>>n;
	for(int i = 0; i < n;i++)
	{
		cin>>arr[i];
	}

	for(int i = 0; i < n; i++)
	{
		if(cnt[arr[i]] == 0)
		{
			diff++;
		}
		cnt[arr[i]]++;
		while(diff > 2)
		{
			cnt[arr[l]]--;
			if(cnt[arr[l]] == 0)
			{
				diff--;
			}
			l++;
		}
		max_length = max(max_length, i-l+1);
	}
	cout<<max_length;
	return 0;
}