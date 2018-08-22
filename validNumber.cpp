/*************************************************************************
	> File Name: validNumber.cpp
	> Author: ldw
	> Explain: Valid Number 
	> Created Time: Wed 22 Aug 2018 09:59:53 AM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class Solution{
	public:
		bool isNumber(const string &s)
		{
			//c_str函数返回一个C字符串的指针
			return isNumber(s.c_str());
		}
	private:
		bool isNumber(const char *s)
		{
			char *endptr;
			//strtod函数将字符串转成浮点数
			strtod(s,&endptr);
			//一样，说明没变
			if(endptr == s)
				return false;

			for(;*endptr;++endptr)
				if(!(isspace(*endptr)))
					return false;

			return true;
		}
};

int main()
{
	string s1 = "1";
	Solution s;
	cout << boolalpha << s.isNumber(s1) << endl;

	return 0;
}
