#include <iostream>
using namespace std;

// 选择排序函数 (原地排序)
void selectionSort(double arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        // 找到未排序部分的最小元素索引
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx]) 
            {
                min_idx = j;
            }
        }
        // 交换找到的最小元素到当前位置
        double temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() 
{
    cout << "请输入待排序数组中总的元素个数: ";
    int n;
    cin >> n;

    if (n <= 0) 
    {
        cout << "无效的数组大小!" << endl;
        return 1;
    }

    // 动态分配内存
    double* numbers = new double[n];

    cout << "请依次输入待排序的元素的值(用空格或回车分隔):" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> numbers[i];
    }

    // 执行选择排序
    selectionSort(numbers, n);

    // 输出排序结果
    cout << "排序结果: ";
    for (int i = 0; i < n; i++) 
    {
        cout << numbers[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    // 释放内存
    delete[] numbers;

    return 0;
}