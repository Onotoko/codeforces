#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n, inc = 0,dec = 0;
	string s,frist,second;
	// vector<char>frist;
	// vector<char>second;
	//Read data
	cin>>n;
	cin>>s;
	frist = s.substr(0,n);
	second = s.substr(n,n);
	//using substr
	// for(int i = 0; i < n;i++)
	// {
	// 	frist.push_back(s[i]);
	// 	second.push_back(s[n+i]);
	// }

	//Sort data
	sort(frist.begin(),frist.end());
	sort(second.begin(),second.end());

	//Compare first of ticket and half second

	for(int i = 0; i < n;i++)
	{
		if(frist[i] < second[i])
		{
			dec++;
		}
		else if(frist[i] > second[i])
		{
			inc++;
		}
	}
	if(dec == n || inc == n)
	{
		cout<<"YES";
	}
	else
		cout<<"NO";

	return 0;
}