/*************************************************************************
	> File Name: rem1.cpp
	> Author: ldw 
  > Explain: Remove 
	> Created Time: Wed 15 Aug 2018 03:59:32 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
		int remove(vector<int>& nums)
		{
			return distance(nums.begin(),unique(nums.begin(),nums.end()));
		}
};

int main()
{
	Solution s;
	vector<int> nums(3);
	nums[0]=1;
	nums[1]=2;
	nums[2]=1;
	cout << "num:" << s.remove(nums) << endl;

	return 0;
}
