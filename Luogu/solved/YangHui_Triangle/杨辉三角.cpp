#include <iostream>
using namespace std;
unsigned long long fact(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	return n*fact(n-1);
}
unsigned long long com(int n,int m)
{
	return fact(n)/(fact(n-m)*fact(m));
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{

		int*nums = new int[i+1];

		for(int j=0;j<i+1;j++)
		{
			nums[j]=com(i,j);
		}
		for(int j=0;j<i+1;j++)
		{
			if(j!=i)
				cout<<nums[j]<<" ";
			else
				cout<<nums[j]<<endl;
		}
		
		delete[]nums;
	}
		
	return 0;
}