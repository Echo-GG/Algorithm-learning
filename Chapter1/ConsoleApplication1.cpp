//二分查找
#include <iostream>
using namespace std;
int binary_finding(double *arr,int size,double target_)
{
	int low = 0;
	int high = size - 1;
	int mid = (low + high) / 2;
	double guess = arr[mid];
	while (low <= high)
	{
		if (guess == target_)
		{
			cout << "找到了目标元素" << target_ << "该元素在原数组中对应的下标为" << mid << endl;
			return mid;
		}
		else if (guess > target_)
		{
			high = mid - 1;
		}
		else if (guess < mid)
		{
			low = mid + 1;
		}
		cout << "没有找到目标元素" << endl;
		return 0;
	}
}
int main()
{
	int n;
	cout << "请输入待查找的数组元素的个数" << endl;
	cin >> n;
	double* num = new double[n];
	cout << "请依次输入待查找数组的各元素信息(相邻两个元素的输入用空格或者换行符隔开)" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> *(num + i);
	}
	double target;
	cout << "请输入待查找的元素的值" << endl;
	cin >> target;
	binary_finding(num, n,target);
	

	delete[]num;
}