/*************************************************************************
	> File Name: binsea.cpp
	> Author: ldw
	> Explain: Search in Rotated Sorted Array 
	> Created Time: Wed 15 Aug 2018 04:36:49 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
	int search(vector<int>& nums,int target)
	{
		int first=0,last=nums.size();
		while(first != last)
		{
			const int mid = first + (last-first)/2;
			if(nums[mid] == target)
				return mid;
			if(nums[first] <= nums[mid])
			{
				if(nums[first]<=target && target<nums[mid])
					last = mid;
				else
					first = mid+1;
			}
			else
			{
				if(nums[mid]<target && target<=nums[last-1])
					first = mid+1;
				else
					last = mid;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> nums(7);
	nums[0] = 4;
	nums[1] = 5;
	nums[2] = 6;
	nums[3] = 7;
	nums[4] = 0;
	nums[5] = 1;
	nums[6] = 2;
	cout << "num:" << s.search(nums,2) << endl;

	return 0;
}
