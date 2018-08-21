/*************************************************************************
	> File Name: implementStrstr.cpp
	> Author: ldw
	> Explain: Implement strStr()
	> Created Time: Tue 21 Aug 2018 03:17:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution{
	public:
		int strStr(const string &haystack,const string &needle)
		{
			if(needle.empty())
				return 0;

			const int N = haystack.size()-needle.size()+1;
			for(int i=0;i<N;i++)
			{
				int j = i;
				int k = 0;
				while(j<haystack.size() && k<needle.size() && haystack[j]==needle[k])
				{
					j++;
					k++;
				}
				if(k == needle.size())
					return i;
			}
			return -1;
		}
};

int main()
{
	Solution s;
	string s1 = "asd";
	string s2 = "s";
	cout << "i:" << s.strStr(s1,s2) << endl;

	return 0;
}
