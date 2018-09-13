#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	int n,tmp, cnt;
	vector<int> m;
	stack<int>s;
	for(;;)
	{
		cnt= 1;
		cin>>n;
		if(n == 0)
		{
			break;
		}
		for(int i = 0; i < n;i++)
		{
			cin>>tmp;
			m.push_back(tmp);
		}
		for(int i = 0; i < n; i++)
		{
			int val = 0;
			while(!s.empty())
			{
				val = s.top();
				if(val == cnt)
				{
					cnt++;
					s.pop();
				}
				else
					break;
			}
			if(m[i] != cnt)
			{
				s.push(m[i]);
			}
			else
			{
				cnt++;
			}

		}
		while(!s.empty())
		{
			int val;
			val = s.top();
			if(val == cnt)
			{
				cnt++;
				s.pop();
			}
			else
				s.pop();
		}
		if(cnt == n+1)
		{
			cout<<"yes"<<"\n";
		}
		else
		{
			cout<<"no"<<"\n";
		}

		m.clear();
	}
	return 0;
}