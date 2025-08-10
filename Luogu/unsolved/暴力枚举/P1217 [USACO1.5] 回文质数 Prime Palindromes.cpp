#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> global_primes;

void generate_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            global_primes.push_back(i);
            if ((long long)i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
}

bool isPrime(int n) {
    if (n <= 1) 
        return false;
    if (n == 2) 
        return true;
    if (n % 2 == 0)
        return false;
    int limit = sqrt(n);
    for (int i = 0; i < global_primes.size(); i++) {
        int p = global_primes[i];
        if (p > limit) {
            break;
        }
        if (n % p == 0) {
            return false;
        }
    }
    return true;
}

long long reverseNumber(long long n) {
    if (n == 0) 
        return 0;
    long long rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int* find_palindromes(const int& a, const int& b, int &SIZE) {
    vector<int> pals;
    if (a <= 0 && 0 <= b) {
        pals.push_back(0);
    }

    int min_digits = (a > 0) ? static_cast<int>(floor(log10(a))) + 1 : 1;
    int max_digits = (b > 0) ? static_cast<int>(floor(log10(b))) + 1 : 1;

    for (int len = min_digits; len <= max_digits; len++) {
        int half = (len + 1) / 2;
        long long start = 1;
        for (int k = 0; k < half - 1; k++) {
            start *= 10;
        }
        long long end = start * 10 - 1;

        long long base_val = 1;
        for (int k = 0; k < half; k++) {
            base_val *= 10;
        }

        long long min_pal, max_pal;
        if (len % 2 == 0) {
            min_pal = start * base_val + reverseNumber(start);
            max_pal = end * base_val + reverseNumber(end);
        } else {
            min_pal = start * (base_val / 10) + reverseNumber(start / 10);
            max_pal = end * (base_val / 10) + reverseNumber(end / 10);
        }

        if (max_pal < a || min_pal > b) {
            continue;
        }

        for (long long i = start; i <= end; i++) {
            long long pal;
            if (len % 2 == 0) {
                long long rev = reverseNumber(i);
                pal = i * base_val + rev;
            } else {
                long long rev = reverseNumber(i / 10);
                pal = i * (base_val / 10) + rev;
            }

            if (pal < a) 
                continue;
            if (pal > b) 
                break;

            pals.push_back(static_cast<int>(pal));
        }
    }

    SIZE = pals.size();
    int* arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = pals[i];
    }
    return arr;
}

int main() {
    generate_primes(50000);
    int a, b;
    cin >> a >> b;

    int size = 0;
    int* nums = find_palindromes(a, b, size);

    for (int i = 0; i < size; i++) {
        if (isPrime(nums[i])) {
            cout << nums[i] << endl;
        }
    }

    delete[] nums;
    return 0;
}