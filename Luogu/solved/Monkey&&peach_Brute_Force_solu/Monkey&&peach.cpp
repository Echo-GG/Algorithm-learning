#include <iostream>
using namespace std;
void update(int& number)
{
	number-=(number*0.5+1);	
}

int main()
{
	int n;
	cin>>n;
	int flag=0;
	for(int i=100000000;i>0;i--)
	{
		int temp = i;
		for(int j=0;j<n-1;j++)
		{
			update(temp);
			if(temp!=1&&temp%2!=0)
			{
				break;
			}
			if(temp==1&&i%2==0)
			{
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	
	return 0;
}