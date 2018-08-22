/*************************************************************************
	> File Name: maxSubArray.cpp
	> Author: ldw
	> Explain: Maximum SubArray
	> Created Time: Wed 22 Aug 2018 09:31:44 PM CST
 ************************************************************************/

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

class Solution{
	public:
		//动态规划
		int maxSubArray(vector<int> &nums)
		{
			int result = INT_MIN,f=0;
			for(int i=0;i<nums[i];i++)
			{
				f = max(f+nums[i],nums[i]);
				result = max(result,f);
			}
			return result;
		}
};

int main()
{
	int a[5] = {1,2,-3,4,-5};
	vector<int> b(a, a+5);
	Solution s;
	cout << "max:" << s.maxSubArray(b) << endl;

	return 0;
}
