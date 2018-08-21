/*************************************************************************
	> File Name: validPalindrome.cpp
	> Author: ldw
	> Explain: validPalindrome 
	> Created Time: Tue 21 Aug 2018 02:08:38 PM CST
 ************************************************************************/

#include<iostream>
#include<ctype.h>
using namespace std;

bool isPalindrome(string s)
{
	int i,j;
	for(i=0,j=s.length()-1;i<j;++i,--j)
	{	
		//检测如果不是字母和数字，加1继续往下走
		while(i<j && !isalnum(s[i]))
			++i;
		while(i<j && !isalnum(s[j]))
			++j;
		//头尾不相等，则返回false
		if(i<j && tolower(s[i])!=tolower(s[j]))
			return false;
	}
	return true;
}

int main()
{
	string s = "abccba";
	cout << boolalpha << isPalindrome(s) << endl;

	return 0;
}
