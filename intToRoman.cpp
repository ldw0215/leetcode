/*************************************************************************
	> File Name: intToRoman.cpp
	> Author: ldw
	> Explain: integer To Roman
	> Created Time: Wed 22 Aug 2018 10:52:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution{
	public:
		string intToRoman(int num)
		{
			const int radix[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
			const string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

			string roman;
			for(size_t i=0;num>0;++i)
			{
				int count = num/radix[i];
				num %= radix[i];
				for(;count>0;--count)
					roman += symbol[i];
			}
			return roman;
		}
};

int main()
{
	Solution s;
	cout << "roman:" << s.intToRoman(5) << endl;

	return 0;
}
