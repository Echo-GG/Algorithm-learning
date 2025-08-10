#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
	if(n<=1)
		return false;
	else if(n==2)
		return true;
	if(n>3&&n%2==0)
		return false;
	for(int i=3;i<=sqrt(n);i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	for(int i=0;i<nums.size();)
	{
		if(!isPrime(nums[i]))
		{
			nums.erase(nums.begin()+i);
		}
		else
		{
			i++;
		}
	}
//	for(int num:nums)
//	{
//		cout<<num<<" ";
//	}
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<" ";
	}
	
	return 0;
}