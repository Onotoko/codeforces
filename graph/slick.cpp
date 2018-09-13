#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#define MAX 250
using namespace std;

int main()
{
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	int n, m;
	map<int,int>slicks;
	int mat[MAX][MAX] = {{0,0}};
	int v[MAX][MAX] = {{0,0}};
	int cnt, slick;
	queue<pair<int,int> >q;
	while(1)
	{
		cin>>n>>m;
		if(n == 0 && m == 0)
		{
			break;
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < m; j++)
			{
				cin>>mat[i][j];
				v[i][j] = 0;
			}
		}
		slicks.clear();
		cnt = 0;
		//Find slick
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				slick = 0;
				if(mat[i][j] && !v[i][j])
				{
					q.push(make_pair(i,j));
					v[i][j] = 1;
					slick+=1;
					while(!q.empty())
					{
						pair<int,int> point = q.front();
						q.pop();
						for(int k = 0; k < 4; k++)
						{
							int kx = point.first + dx[k];
							int ky = point.second + dy[k];
							if ((kx>=0 && kx < n) && (ky>=0 && ky < m) && (mat[kx][ky]) && (!v[kx][ky]))
							{
								q.push(make_pair(kx,ky));
								v[kx][ky] = 1;
								slick +=1;
							}
						}
					}//end while
					slicks[slick]++;
					cnt+=1;
				}//end if

			}//end for rows
		}//end for cols
		cout<<cnt<<"\n";
		for(auto i = slicks.begin(); i !=slicks.end(); ++i)
		{
			cout<<i->first<<" "<<i->second<<"\n";
		}

	}
	return 0;
}