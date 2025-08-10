#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
class Students
{
private:
    float*scores;
    int number;
public:
	Students()
    {
    	scores = nullptr;
    	number = 0;
	}
    Students(int m,float* other):number(m)
    {
        scores = new float[number];
        for(int i=0;i<number;i++)
        {
            *(scores+i) = other[i];
        }
    }
    Students(const Students&other):number(other.number)
    {
    	scores = new float[number];
    	for(int i=0;i<number;i++)
    	{
    		scores[i] = other.scores[i];
		}
	}
	Students& operator = (const Students&other)
	{
		if(this!=&other)
		{
			delete[]scores;
			number = other.number;
			scores = new float [number];
			for(int i=0;i<number;i++)
			{
				scores[i] = other.scores[i];
			}
		}
		return *this;
	}
    float get_avg()const
    {
    	float *temp = new float[number];
    	for(int i=0;i<number;i++)
    	{
    		temp[i] = scores[i];
		}
        sort(temp,temp+number,[](const float&a,const float&b)
             {
                 return a<b;
             });
        float sum = 0.0;
        for(int i=1;i<number-1;i++)
        {
            sum+=temp[i];
        }
        sum/=(number-2);
        delete[]temp;
        return sum;
    }
    ~Students()
    {
        delete[]scores;
    }
    void display()
    {
        cout<<fixed<<setprecision(2)<<get_avg()<<endl;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;

    Students*students = new Students[n];
    for(int i=0;i<n;i++)
    {
        float*other = new float[m];
        for(int j=0;j<m;j++)
        {
            cin>>*(other+j);
        }
        students[i] = Students(m,other);
        delete[]other;
    }
    sort(students,students+n,[](const Students&a,const Students&b)
         {
             return a.get_avg()<b.get_avg();
         });
    students[n-1].display();
    delete[]students;
    return 0;
}