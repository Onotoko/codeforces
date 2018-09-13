#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
    The idea of this problem:
	- Step 1: Push all citizen into queue(get min ( p & c), because we loop over c commands)
    - Step 2: Loop commnads:
         + Step 2.1: If the commnand is 'N'-> We get front queue and push it into result array
            (it called: processed), and we push this back to queue
		 + Step 2.1: If the command is 'E'-> We loop over queue to find the citizen has order which
            equals x, if found -> delete it. Then we push x to front of queue
	- Step 3: Print output

	The complexity of this problem:
	- Step 1: O(k), k = min(p,c)
	- Step 2: 
	+ Loop c commands: O(C)
	+ Loop queue when the command is E: O(k)
	->Worst case O(c*k)
	-> The complexity: O(k) + O(c*k) ~ O(c*k)
*/
int main()
{
	long int p, c;
	char n;
	long int x, temp;
	deque<long int> admited;
	vector<long int> processed;
	int cnt = 0;
	for(;;)
	{
		cin>>p>>c;
		if(p == 0 || c == 0)
			break;
		p = min(p,c);
		for(int i = 0 ; i < p ;i++)
		{
			admited.push_back(i+1);
		}
		for(int i= 0 ; i< c;i++)
		{
			cin>>n;
			if(n == 'N')
			{
 				temp = admited.front();
				processed.push_back(temp);
				admited.pop_front();
				admited.push_back(temp);
			}
			else if(n == 'E')
			{
				cin>>x;
				//Get element x out of queue
				for ( auto it = admited.begin(); it != admited.end(); ++it )
				{
					if(*it == x)
					{
						admited.erase(it);
						break;
					}	
				}
				admited.push_front(x);
			}
		}
		admited.clear();
		//Print output
		cout<<"Case "<<++cnt<<":\n";
		for(int i = 0; i < processed.size(); i++)
		{
			printf("%ld\n",processed[i]);
		}
		processed.clear();
	}
	return 0;
}
