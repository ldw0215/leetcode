/*************************************************************************
	> File Name: twosum.cpp
	> Author: ldw
	> Explain: Two Sum 
	> Created Time: Wed 15 Aug 2018 08:09:21 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include <unordered_map>
using namespace std;

class Solution{
	public:
		vector<int> twoSum(vector<int> &nums,int target)
		{
			unordered_map<int,int> mapping;
			vector<int> result;
			for(int i=0;i<nums.size();i++)
			{
				mapping[nums[i]] = i;
			}
			for(int i=0;i<nums.size();i++)
			{
				const int gap = target-nums[i];
				cout << "gap:" << gap << endl;
				if(mapping.find(gap)!=mapping.end() && mapping[gap]>i)
				{
					result.push_back(i+1);
					result.push_back(mapping[gap]+1);
					break;
				}

			}
			return result;
		}
};

int main()
{
	Solution s;
	vector<int> nums(4);
	nums[0] = 2;
	nums[1] = 7;
	nums[2] = 11;
	nums[3] = 15;
	s.twoSum(nums,9);
	
	return 0;

}
