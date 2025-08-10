//#include <iostream>
//#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int* nums = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>*(nums+i);
	}
	unordered_set<int>sums;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			sums.insert(nums[i]+nums[j]);
		}
	}
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		if(sums.count(nums[i]))
			cnt++;
	}
	cout<<cnt<<endl;
	delete[]nums;
	return 0;
}