/*************************************************************************
	> File Name: removeElement.cpp
	> Author: ldw
	> Explain: Remove Element 
	> Created Time: Thu 16 Aug 2018 09:09:45 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
		int removeElement(vector<int>& nums,int target)
		{
			return distance(nums.begin(),remove(nums.begin(),nums.end(),target));
		}
};

int main()
{
	Solution s;
	vector<int> nums(3);
	nums[0] = 1;
	nums[1] = 6;
	nums[2] = 8;
	cout << "len:" << s.removeElement(nums,8) << endl; 

	return 0;
}
