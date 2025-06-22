#include <iostream>
using namespace std;

// 前置声明
template<typename T>
T pop(T*& arr, int& size, int index);
template<typename T>
void append(T*& arr, int& size, T element);

// 查找最小元素的索引
int find_smallest(double* arr, int size)
{
    if (size == 0)
        return -1; // 处理空数组

    double smallest = arr[0];
    int smallest_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

// 选择排序
void selection_Sort(double* arr, int size)
{
    double* result = nullptr;   // 初始化为空指针
    int result_size = 0;        // 结果数组大小

    int current_size = size;    // 保存当前数组大小

    while (current_size > 0)
    {
        int smallest_index = find_smallest(arr, current_size);
        if (smallest_index == -1)
            break; // 安全检查

        double tmp = pop(arr, current_size, smallest_index);
        append(result, result_size, tmp);
    }

    // 输出排序结果
    for (int i = 0; i < result_size; i++)
    {
        cout << result[i];
        if (i < result_size - 1)
            cout << " ";
    }
    cout << endl;

    delete[] result; // 释放结果数组
}

// 弹出指定索引的元素并缩小数组
template<typename T>
T pop(T*& arr, int& size, int index)
{
    T target = arr[index];
    T* tmp = new T[size - 1];

    // 复制索引前的元素
    for (int i = 0; i < index; i++)
    {
        tmp[i] = arr[i];
    }

    // 复制索引后的元素
    for (int i = index; i < size - 1; i++)
    {
        tmp[i] = arr[i + 1];
    }

    delete[] arr; // 释放原数组
    arr = tmp;    // 更新指针
    size--;       // 减小大小

    return target;
}

// 向数组末尾添加元素
template<typename T>
void append(T*& arr, int& size, T element)
{
    T* tmp = new T[size + 1];

    // 复制原数组内容
    for (int i = 0; i < size; i++)
    {
        tmp[i] = arr[i];
    }

    // 添加新元素
    tmp[size] = element;

    // 释放原数组（如果是首次添加，arr 可能是 nullptr）
    if (arr)
    {
        delete[] arr;
    }

    arr = tmp; // 更新指针
    size++;    // 增加大小
}

int main()
{
    cout << "请输入待排序数组中总的元素个数: ";
    int n;
    cin >> n;


    cout << "请依次输入待排序的元素的值: ";
    double* num = new double[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    selection_Sort(num, n);

    delete[] num;
    return 0;
}