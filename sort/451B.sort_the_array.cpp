#include <iostream>
#include <algorithm>
using namespace std;
#define ENABLE_FLAG 1
int main()
{
	int n;
	int arr[100000] ={0};
	int arr_sort[100000] = {0};
	int flag = 0;
	int l = 0,r= 0;
	//Read input
	cin>>n;
	for(int i= 0; i < n;i++)
	{
		cin>>arr[i];
		arr_sort[i] = arr[i];
	}

	//Sorting array
	sort(arr_sort, arr_sort+n);
	//Difference between two array 
	for(int i = 0; i < n;i++)
	{

	    if(arr[i] != arr_sort[i] && !flag)
		{
			l = i;
			flag |= ENABLE_FLAG;
		}
		else if(arr[i] != arr_sort[i])
		{
			r = i;
		}
	}
	
	//Reverse 
	for(int u = l, v = r; u< v;u++, v--)
	{
		swap(arr[u],arr[v]);
		if(arr[u] != arr_sort[u] || arr[v] != arr_sort[v])
		{
			cout<<"no";
			return 0;
		}
	}

	//Print output
	cout<<"yes"<<"\n";
	cout<<l+1<<" "<<r+1;
	return 0;
}