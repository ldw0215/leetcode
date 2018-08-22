/*************************************************************************
	> File Name: lenOfLastWord.cpp
	> Author: ldw
	> Explain: Length Of Last Word
	> Created Time: Wed 22 Aug 2018 01:59:26 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
	public:
		int lengthOfLastWord(const string &s)
		{
			auto first = find_if(s.rbegin(),s.rend(),::isalpha);
			auto last = find_if_not(first,s.rend(),::isalpha);
			return distance(first,last);
		}
};

int main()
{
	string s1 = "l dw";
	Solution s;
	cout << "len:" << s.lengthOfLastWord(s1) << endl;

	return 0;
}
