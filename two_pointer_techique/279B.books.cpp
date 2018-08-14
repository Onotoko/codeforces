#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int sum= 0, i,l = 0,cnt = 0, ans = 0;
	int n,t;
	int arr[100000] = {0};
	cin>>n>>t;
	for(i = 0; i < n;i++)
	{
		cin>>arr[i];
	}
	sum = 0;
	for(i = 0; i < n;i++)
	{
		sum += arr[i];
		if (sum <= t)
		{
			ans = max(ans, i-l+1);
		}
		else
		{
			sum -= arr[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}