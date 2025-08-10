#include <iostream>
using namespace std;
int count[100];
int main()
{
	int s1,s2,s3;
	cin>>s1>>s2>>s3;
	int max_sum = s1+s2+s3;
	for(int i=1;i<=s1;i++)
	{
		for(int j=1;j<=s2;j++)
		{
			for(int k=1;k<=s3;k++)
			{
				count[i+j+k]++;
			}
		}
	}
	int max_count = 0;
	for(int i=3;i<=max_sum;i++)
	{
		if(count[i]>max_count)
		{
			max_count = count[i];
		}
	}
	int ans = 3;
	for(int i=3;i<=max_sum;i++)
	{
		if(count[i]==max_count)
		{
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}