#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n,m,x,y,i,j = 0;
	int soldiers[100000] = {0},vests[100000] ={0};
	//vector<Point> max_res;
	map<int, int> max_res;
	//Read data
	cin>>n>>m>>x>>y;
	for(i = 0; i < n;i++)
	{
		cin>>soldiers[i];
	}
	for(i = 0; i < m;i++)
	{
		cin>>vests[i];
	}
	//Loop find max soldiers and vests
	i = 0;
	while(i < n && j < m)
	{
		if((soldiers[i] - x <= vests[j]) && (soldiers[i] + y >= vests[j]))
		{
			max_res[i+1] = j+1;
			j++;
			i++;
		}
		if(soldiers[i] - x > vests[j])
		{
			j++;
		}
		else if (soldiers[i] +y < vests[j])
		{
			i++;
		}
	}
	cout<<max_res.size()<<"\n";
	map<int,int> ::iterator it;
	for(it = max_res.begin();it !=max_res.end();it++)
	{
		cout<<it->first<<" "<<it->second<<"\n";
	}
	return 0;
}