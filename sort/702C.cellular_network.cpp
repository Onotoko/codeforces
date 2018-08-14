#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	vector<long long int>cells;
	vector<long long int>nets;
	vector<long long int>distance;
	long long int tmp;
	//Read input
	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>tmp;
		cells.push_back(tmp);
	}
	for(int i = 0; i < m; i++)
	{
		cin>>tmp;
		nets.push_back(tmp);
	}
	if(n == m == 1)
	{
		cout<<abs(cells[0] - nets[0]);
	}
	else
	{
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				distance.push_back(abs(nets[i] - cells[j]));
			}
		}

		//sort distance
		sort(distance.begin(), distance.end());

		cout<<distance[n];
	}

	return 0;
}