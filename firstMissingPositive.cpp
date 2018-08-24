/*************************************************************************
	> File Name: firstMissingPositive.cpp
	> Author: ldw
	> Explain: First Missing Positive
	> Created Time: Fri 24 Aug 2018 09:02:15 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
	public:
		int firstMissingPositive(vector<int> &nums)
		{
			bucket_sort(nums);
	
			for(int i=0;i<nums.size();++i)
				if(nums[i] !=(i+1))
					return i+1;
			return nums.size()+1;
		}
	private:
		static void bucket_sort(vector<int> &A)
		{
			const int n = A.size();
			for(int i=0;i<n;i++)
			{
				while(A[i] != i+1)
				{
					if(A[i]<=0 || A[i]>n || A[i]==A[A[i]-1])
						break;
					swap(A[i],A[A[i]-1]);
				}
			}
		}
};

int main()
{
	Solution s;
	int a[] = {1,2,0};
	vector<int> b(a,a+3);
	cout << "positive:" << s.firstMissingPositive(b) << endl;

	return 0;
}
