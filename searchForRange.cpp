/*************************************************************************
	> File Name: searchForRange.cpp
	> Author: ldw
	> Explain: Search For a Range
	> Created Time: Fri 24 Aug 2018 10:11:06 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution{
	public:
		vector<int> searchRange(vector<int> &nums,int target)
		{
			//lower_bound函数，二分查找第一个大于或等于target
			const int l = distance(nums.begin(),lower_bound(nums.begin(),nums.end(),target));
			//upper_bound函数，二分法找第一个大于target
			const int u = distance(nums.begin(),prev(upper_bound(nums.begin(),nums.end(),target)));
			//not found
			if(nums[l] != target)
				return vector<int>{-1,-1};
			else
				return vector<int>{l,u};
		}
};

int main()
{
	int a[] = {5,7,7,8,8,10};
	vector<int> b(a,a+5);
	Solution s;
	vector<int> res;
	res = s.searchRange(b,8);
	for(int i=0;i<res.size();i++)
		cout << "res:" << res[i] << endl;

	return 0;
}
