#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
	The idea of this problem: We using stack to contain operator(To write it on 'convert2rpn' function)
    - Step 1 : Loop over the expression:
		+ If the element ith is operand  -> Push it to the result of string
		+ If the element ith is operator:
			* If stack is empty -> push it to stack
			* Otherwise, get first element of stack and check priority between them
			   -- If it is '(', push it to stack
			   -- If operator in stack is higher priority than the element ith: Pop it out of stack
                  and push it to the result of string and push the element ith into stack
			   -- Otherwise, push the element ith into stack
		+ If the element ith is '(': push it into stack
		+ If the element ith is ')': Pop all element from stack, when we miss '('->stop
    - Step 2: Pop all remain element from stack, and stop when stack is empty
    - Step 3: Print output

	The complexity of this problem:
	- Step 1:
        + Loop over expression:O(N)
        + Loop over stack when miss ')':O(k)
    -> Total time for this operator:O(N*k), w have max k = N/2 -> O(N^2)
	- Time for get all remain element from stack: O(M), M <=N/2
	-> The complexity of this problem: O(N^2) + O(M) -> O(N^2)
*/

char operators[5] = {'+','-','*','/','^'};
int  is_operand(char c)
{
	return (c >= 'a' && c <= 'z')? 1:0;
}

int is_operator(char c)
{
	for(int i = 0; i < 5; i++)
	{
		if(c == operators[i])
			return 1;
	}
	return 0;
}

int get_priority(char op1, char op2)
{
	int pos1, pos2;
	for(int i = 0; i < 5; i++)
	{
		if(op1 == operators[i])
			pos1 = i;
		else if(op2 == operators[i])
			pos2 = i;
	}
	return (pos1 < pos2);
}

void convert2rpn(string s)
{
	stack<char>op;
	string rpn = "";
	char temp;
	for(int i = 0; i < s.length();i++)
	{
		if(is_operand(s[i]))
		{
			rpn.push_back(s[i]);
		}
		else if(is_operator(s[i])) 
		{
			if(op.empty())
			{
				op.push(s[i]);
			}
			else 
			{
				temp = op.top();
				if(temp == '(')
				{
					op.push(s[i]);
				}
				else if (get_priority(s[i], temp))
				{
					rpn+=temp;
					op.pop();
					op.push(s[i]);
				}
				else
				{
					op.push(s[i]);
				}

			}
		}
		else if(s[i] == '(')
		{
			op.push(s[i]);
		}
		else if(s[i] == ')')
		{
			while((temp = op.top()) != '(')
			{
				rpn+=temp;
				op.pop();
			}
			op.pop();
		}
	}
	//Pop remain out of stack
	while(!op.empty())
	{
		rpn+=op.top();
		op.pop();
	}
	//Print output
	cout<<rpn;
}

int main()
{
	int t;
	string exprs;
	cin>>t;
	while(t--)
	{
		cin>>exprs;
		convert2rpn(exprs);
		cout<<"\n";
	}

	return 0;
}
