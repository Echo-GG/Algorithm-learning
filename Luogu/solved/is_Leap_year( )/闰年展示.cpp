#include <iostream>
#include <algorithm>
using namespace std;
bool is_Leap_year(int n)
{
	if(n%400==0)
		return true;
	if(n%4==0&&n%100!=0)
		return true;
	return false;
}
int main()
{
	int x,y;
	cin>>x>>y;
	int result_years[1000];
	for(int i=0;i<1000;i++)
	{
		result_years[i] = 0;
	}
	int cnt = 0;
	int *years = new int[y-x+1];
	for(int i=0;i<y-x+1;i++)
	{
		years[i] = x+i;
		if(is_Leap_year(years[i]))
		{
			result_years[cnt++] = years[i];	
		}
	}	
	sort(result_years,result_years+cnt,[](const int&a,const int&b)
	{
		return a<b;
	});
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)
	{
		cout<<result_years[i]<<" ";
	}
	delete[]years;
	return 0;
}