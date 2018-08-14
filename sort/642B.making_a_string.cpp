#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, cnt = 0, l, r;
	long long int sum = 0;
	long long int a[26] = {0};

	//Read input
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		// sum += a[i];
	}

	//Sort data
	sort(a,a+n);
	while(cnt <n -1)
	{
		l = 0;
		r = 1;
		cnt = 0;
		while(l < n-1 && r < n)
		{
			if(a[l] == a[r] && a[l])
			{
				a[l]--;
			}
			else
				cnt++;
			l++;
			r++;
		}
		sort(a,a+n);
	}
	/* Good way
	    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
            a[i]--;

        else if(a[i]>a[i-1])
            a[i]=a[i-1]-1;
            
        if(a[i]<0)
            a[i]=0;
    }
	*/

	for(int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	cout<<sum;
	return 0;
}