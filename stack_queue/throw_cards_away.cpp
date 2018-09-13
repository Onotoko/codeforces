#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n, step = 1;
	stack<int>s_throw_cards;
	queue<int>q_remain_cards;
	vector<int>v_throw_cards;

	for(;;)
	{
		//Read input
		cin>>n;
		if(n == 0)
		{
			break;
		}
		else if(n == 1)
		{
			cout<<"Discarded cards:"<<"\n";
			cout<<"Remaining card: "<<n<<"\n";
		}
		else
		{
			//Add all cards into stack
			for(int i = n; i > 0;i--)
			{
				s_throw_cards.push(i);
			}
			//Throw card from stack then push remain in queue
			step = 1; 
			while(!s_throw_cards.empty())
			{
				if(step%2 !=0)
				{
					v_throw_cards.push_back(s_throw_cards.top());
					s_throw_cards.pop();
				}
				else
				{
					q_remain_cards.push(s_throw_cards.top());
					s_throw_cards.pop();
				}
				step++;
			}
			//Get remain in queue
			while(!q_remain_cards.empty() && q_remain_cards.size() > 1)
			{
				if(step % 2 ==0)
				{
					q_remain_cards.push(q_remain_cards.front());
					q_remain_cards.pop();
				}
				else
				{
					v_throw_cards.push_back(q_remain_cards.front());
					q_remain_cards.pop();
				}
				step++;
			}
			//print output
			cout<<"Discarded cards:";
			for(int i = 0; i < v_throw_cards.size()-1;i++)
			{
				cout<<" "<<v_throw_cards[i]<<",";
			}
			cout<<" "<<v_throw_cards[v_throw_cards.size() - 1]<<"\n";
			cout<<"Remaining card:";
			cout<<" "<<q_remain_cards.front() <<"\n";
			q_remain_cards.pop();
			v_throw_cards.clear();
		}
	
	}

	return 0;
}