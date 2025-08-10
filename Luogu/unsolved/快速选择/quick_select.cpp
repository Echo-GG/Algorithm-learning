#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int quickselect(int nums[], int left, int right, int k) {
    if (left == right) return nums[left];
    
    // 随机选择基准值
    int pivotIndex = left + rand() % (right - left + 1);
    int pivot = nums[pivotIndex];
    
    // 将基准值移到最右边
    swap(nums[pivotIndex], nums[right]);
    
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    
    if (i == k) {
        return nums[i];
    } else if (i < k) {
        return quickselect(nums, i + 1, right, k);
    } else {
        return quickselect(nums, left, i - 1, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    srand(time(0)); // 初始化随机数种子
    
    int n, k;
    cin >> n >> k;
    int* nums = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << quickselect(nums, 0, n - 1, k) << endl;
    
    delete[] nums;
    return 0;
}
//Failed Try1:
//Bubble sort
//
//Failed Try2:
//using sort from <algorithm>
//
//Failed Try 3:
//	#include <iostream>
//#include <algorithm>
//using namespace std;
//void quickSort(int arr[], int left, int right) 
//{
//    if (left >= right) 
//		return;
//		
//    // 选择基准值（这里选最右边元素）
//    int pivot = arr[right];
//    int i = left;
//    
//    // 分区操作
//    for (int j = left; j < right; j++) {
//        if (arr[j] < pivot) {
//            swap(arr[i], arr[j]);
//            i++;
//        }
//    }
//    swap(arr[i], arr[right]);
//    
//    // 递归排序左右两部分
//    quickSort(arr, left, i - 1);
//    quickSort(arr, i + 1, right);
//}
//int main()
//{
//    int n,k;
//    cin>>n>>k;
//    int*nums = new int[n];
//    for(int i=0;i<n;i++)
//    {
//    	cin>>nums[i];
//	}
//	quickSort(nums,0,n-1);
//    cout<<nums[k]<<endl;
//    delete[]nums;
//}