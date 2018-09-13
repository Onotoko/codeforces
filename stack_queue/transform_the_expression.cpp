#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
	Ý tưởng của bài toán: Sử dụng stack để chứa các toán tử(operator)(viết trong hàm 'convert2rpn')
	- Lặp qua chiều dài của biêủ thức:
		+ Nếu phần tử thứ i là 1 toán hạng -> đưa nó vào chuỗi kết quả
		+ Nếu phần tử thứ i là 1 toán tử:
			* Nếu stack đang trống -> push vào stack
			* Ngược lại, lấy phần tử đầu stack để xác định mức độ ưu 
			  tien giữa các toán tử
			   -- Nếu toán tử trong stack là dấu mở ngoặc, push phần tử
			   	  thứ i vào trong stack
			   -- Nếu toán tử trong stack có độ ưu tiên cao hơn: Lấy ra
			      khỏi stack, đưa vào chuỗi kết quả và push toán tử thứ i
			      vào stack
			   -- Ngược lại push phần tử thứ i vào stack

		+ Nếu phần tử thứ i là dấu mở ngoặc: push vào stack
		+ Nếu phần tử thứ i là dấu đóng ngoặc: Lấy hết tất cả các phần tử
		  trong stack đưa vào chuỗi kết quả, đến khi gặp dấu mở ngoặc
	- Lấy hết các phần tử trong stack, đưa vào chuỗi kết quả
	- In kết quả ra màn hình

	Độ phức tạp của bài toán: 
	- Thời gian duyệt hết biểu thức có độ dài N: O(N)
	+ Thời gian duyệt qua while trong stack khi gặp dấu đóng ngoặc là O(k)
	-> Tổng thời gian:O(N*k), tối đa k = N/2 -> O(N^2)
	- Thời gian lấy hết các phần tử còn lại trong stack: O(M), M <=N/2
	-> Độ phức tạp của bài toán: O(N^2) + O(M) -> O(N^2)
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