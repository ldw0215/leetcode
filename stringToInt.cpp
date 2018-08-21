/*************************************************************************
	> File Name: stringToInt.cpp
	> Author: ldw
	> Explain: String to Integer
	> Created Time: Tue 21 Aug 2018 03:50:41 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<string>
using namespace std;

class Solution{
	public:
		int myAtoi(const string &str)
		{
			int num = 0;
			int sign = 1;
			const int n = str.size();
			int i = 0;

			//检测空字符
			while(str[i]==' ' && i<n)
				i++;

			if(str[i] == '+')
			{
				i++;
			}
			else if(str[i]=='-'){
				sign = -1;
				i++;
			}
			
			for(;i<n;i++)
			{
				if(str[i]<'0' || str[i]>'9')
					break;
				if(num>INT_MAX /10 || (num == INT_MAX/10 && (str[i]-'0')>INT_MAX % 10))
				{
					return sign == -1 ? INT_MAX : INT_MAX;
				}
				num = num*10 + str[i] -'0';
			}
			return num*sign;
		}
};

int main()
{
	Solution s;
	string str = "789";
	char str1[] = {"789"};
	cout << "data:" << s.myAtoi(str) << endl;
	cout << "atoi:" << atoi(str1) << endl;

	return 0;
}
