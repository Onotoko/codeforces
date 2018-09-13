#include <iostream>
#include <stack>
#include <map>
using namespace std;
/*
	The idea of this problem:
	- Step 1: Write formula of molecula to infix expression:
			Example: C(OH)2-> C + (O + H)*2
	- Step 2: Convert infix expression to postfix (RPN)
	- Step 3: Caclulate value of RPN expression:
		+ If we get operand -> push it to stack
		+ If we get operator-> Pop 2 operands in stack and calculate them

	The complexity of this problem:
	- Step 1: O(N)
	- Step 2: O(N^2)
	- Step 3: O(N)
	-> O(N^2)
*/
map<char,int> atom_dict = {{'C',12},{'O',16},{'H',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
char operators[5] = {'+','-','*','/','^'};
int  is_operand(char c)
{
	return (c >= 'A' && c <= 'Z')? 1:0;
}
int is_number(char c)
{
	return (c >= '2' && c <='9')? 1:0;
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
//Step 1
string convert2infix(string s)
{
	string infix ="";
	char star = '*';
	char add  = '+';
	infix += s[0];
	for(int i = 1; i < s.length() ;i++)
	{
		if(is_number(s[i]))
		{
			infix+=star;
			infix+=s[i];
		}
		else if(is_operand(s[i]) || s[i] == '(')
		{
			if(is_operand(s[i-1]) || is_number(s[i-1]))
			{
				infix += add;
				infix += s[i];
			}
			else if(s[i-1] == '(')
			{
				infix += s[i];
			}
			else if(s[i-1] == ')')
			{
				infix += add;
				infix += s[i];
			}
		}
		else if(s[i] == ')')
		{
			infix += s[i];
		}
	}
	return infix;
}
//Step 2
string convert2rpn(string s)
{
	stack<char>op;
	string rpn = "";
	char temp;
	for(int i = 0; i < s.length();i++)
	{
		if(is_operand(s[i]) || is_number(s[i]))
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
	return rpn;
}

//Step 2
int mmass(string s)
{
	int mol = 0;
	int op1, op2;
	stack<int>atomics;
	for(int i = 0; i < s.length(); i++)
	{
		if(is_operand(s[i]) || is_number(s[i]))
		{
			atomics.push(atom_dict[s[i]]);
		}
		else if(is_operator(s[i]))
		{	
			op1 = atomics.top();
			atomics.pop();
			op2 = atomics.top();
			atomics.pop();
			if(s[i] == '+')
			{
				atomics.push(op1 + op2);
			}
			else if(s[i] == '*')
			{
				atomics.push(op1*op2);
			}
		}
	}
	mol = atomics.top();
	atomics.pop();
	return mol;
}
int main()
{
	string formula;
	cin>>formula;
	string infix = convert2infix(formula);
	string rpn = convert2rpn(infix);
	cout<<mmass(rpn)<<"\n";
	return 0;
}
