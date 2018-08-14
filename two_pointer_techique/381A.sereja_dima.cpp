#include <iostream>
using namespace std;
int main()
{
	int n,l,r;
	int point_sereja = 0;
	int point_dima = 0;
	int cards[1000] = {0};
	//Read input
	cin>>n;
	for(int i= 0; i < n;i++)
	{
		cin>>cards[i];
	}
	
	l = 0;
	r = n-1;
	while(l<=r)
	{
		if(cards[l]<cards[r])
		{
			point_sereja+= cards[r];
			r--;
		}
		else
		{
			point_sereja+=cards[l];
			l++;
		}
		if(l<=r)
		{
			if(cards[l] < cards[r])
			{
				point_dima+=cards[r];
				r--;
			}
			else
			{
				point_dima+=cards[l];
				l++;
			}
		}
	}
	cout<<point_sereja<<" "<<point_dima;
	return 0;
}