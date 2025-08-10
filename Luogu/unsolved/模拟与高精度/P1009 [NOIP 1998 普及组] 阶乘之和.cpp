#include <iostream>
#include <cstring> // 用于memset
using namespace std;

const int MAXLEN = 1000; // 假设最大位数

// 高精度乘法：a[] *= x
void multiply(int a[], int &len, int x) {
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int product = a[i] * x + carry;
        a[i] = product % 10;
        carry = product / 10;
    }
    while (carry) {
        a[len++] = carry % 10;
        carry /= 10;
    }
}

// 高精度加法：sum[] += a[]
void add(int sum[], int &sumLen, int a[], int aLen) {
    int carry = 0;
    int newLen = max(sumLen, aLen);
    for (int i = 0; i < newLen; i++) {
        int digitSum = (i < sumLen ? sum[i] : 0) + (i < aLen ? a[i] : 0) + carry;
        sum[i] = digitSum % 10;
        carry = digitSum / 10;
    }
    if (carry) {
        sum[newLen++] = carry;
    }
    sumLen = newLen;
}

int main() {
    int n;
    cin >> n;
    
    int factorial[MAXLEN] = {1}; // 存储当前阶乘
    int factLen = 1;
    
    int sum[MAXLEN] = {0}; // 存储总和
    int sumLen = 1;
    
    for (int i = 1; i <= n; i++) {
        multiply(factorial, factLen, i); // 计算i!
        add(sum, sumLen, factorial, factLen); // 加到总和中
    }
    
    // 输出结果（逆序存储，需要反向输出）
    for (int i = sumLen - 1; i >= 0; i--) {
        cout << sum[i];
    }
    cout << endl;
    
    return 0;
}