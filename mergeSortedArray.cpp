/*************************************************************************
	> File Name: mergeSortedArray.cpp
	> Author: ldw
	> Explain: Merge SortedArray
	> Created Time: Thu 23 Aug 2018 10:10:06 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		void mergeArray(vector<int> &A,int m,vector<int> &B,int n)
		{
			int ia=m-1,ib=n-1,icur=m+n-1;
			while(ia>=0 && ib>=0)
			{
				A[icur--]=A[ia]>=B[ib] ? A[ia--] : B[ib--]; 
			}
			while(ib >= 0)
			{
				A[icur--] = B[ib--];
			}
		}
};

int main()
{
	vector<int> a1(6,1);
	int b[]={2,4,6};
	vector<int> b1(b,b+3);
	Solution s;
	s.mergeArray(a1,3,b1,3);
	for(int i=0;i<a1.size();i++)
		cout << "res:" << a1[i] << endl;

	return 0;
}
