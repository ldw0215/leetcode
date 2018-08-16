/*************************************************************************
	> File Name: climbingStair.cpp
	> Author: ldw
	> Explain: Climbing Stairs 
	> Created Time: Thu 16 Aug 2018 09:55:28 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int climbStair(int n) {
        int f = 1;
        int g = 0;
        while(n--){
            f += g;
            g = f -g;          
        }
        return f;
    }
};

int main()
{
	Solution s;
	cout << "cur:" << s.climbStair(3) << endl;

	return 0;
}
