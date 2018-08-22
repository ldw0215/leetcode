/*************************************************************************
	> File Name: validPar.cpp
	> Author: ldw
	> Explain: Valid Parentheses
	> Created Time: Wed 22 Aug 2018 02:40:07 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

class Solution{
	public:
		bool isValid(string s)
		{
			if(s.empty())
				return true;
			stack<char> sStack;
			for(size_t i=0;i<s.size();i++)
			{
				if(s[i] == '(')
					sStack.push(')');
				else if(s[i] == '[')
					sStack.push(']');
				else if(s[i] == '{')
					sStack.push('}');
				else if(sStack.empty() || sStack.top()!=s[i])
					return false;
				else				
					sStack.pop();
			}
			return sStack.empty();
		}
};

int main()
{
	Solution s;
	string s1 = "()";
	cout << boolalpha << s.isValid(s1) << endl;

	return 0;
}
