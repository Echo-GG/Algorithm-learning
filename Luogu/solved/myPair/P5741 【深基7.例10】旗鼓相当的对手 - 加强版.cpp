#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
template<typename T1,typename T2> 
struct myPair
{
	T1 first;
	T2 second;
};
class Students
{
private:
	string name;
	float grade1,grade2,grade3;
	float sum ;
public:
	Students()
	{
		name = "";
		grade1 = 0;
		grade2 = 0;
		grade3 = 0;
		sum = 0;
	}
	Students(string a,float b,float c,float d):name(a),grade1(b),grade2(c),grade3(d){sum = grade1+grade2+grade3;}
	string get_name()const{return name;}
	bool is_Equal(const Students& other)const
	{
//		if(fabs(sum-other.sum)<=10&&fabs(grade1-other.grade1)<=5&&fabs(grade2-other.grade2)<=5&&fabs(grade3-other.grade3)<=5)
//			return true;
//		return false;
		return (fabs(sum - other.sum) <= 10 &&
        	fabs(grade1 - other.grade1) <= 5 &&
        	fabs(grade2 - other.grade2) <= 5 &&
        	fabs(grade3 - other.grade3) <= 5);
	}
	friend void display(Students*students,int N)
	{
		myPair<Students,Students>*result = new myPair<Students,Students> [N*(N-1)/2];
		int cnt = 0;
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				if(students[i].is_Equal(students[j]))
				{
//					result[cnt++] = {students[i],students[j]};					
					result[cnt].first = students[i];
                    result[cnt].second = students[j];
                    cnt++;			
				}			
			}
		}
		sort(result,result+cnt,[](const myPair<Students,Students>&lhs,const myPair<Students,Students>&rhs)
		{
			if(lhs.first.get_name()!=rhs.first.get_name())
				return lhs.first.get_name()<rhs.first.get_name();
			return lhs.second.get_name()<rhs.second.get_name();
		});
		for(int i=0;i<cnt;i++)
		{
			cout<<result[i].first.get_name()<<" "<<result[i].second.get_name()<<endl;
		}
		delete[]result;
	}
};
int main()
{
	int N;
	cin>>N;
	Students* students = new Students[N];
	for(int i=0;i<N;i++)
	{
		string name;
		float grade1,grade2,grade3;
		cin>>name>>grade1>>grade2>>grade3;
		students[i] = Students(name,grade1,grade2,grade3);
	}
	display(students,N);
	delete[] students;
	
	return 0;
}