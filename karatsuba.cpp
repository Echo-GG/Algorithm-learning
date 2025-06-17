#include <iostream>
#include <string>
#include <algorithm> // for reverse
using namespace std;

// large_number_addition_function
string addStrings(const string& num1, const string& num2) 
{
    string res;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) 
	{
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    
    reverse(res.begin(), res.end());
    return res;
}

// large_number_substraction_function（assume:num1 >= num2）
string subtractStrings(string num1, string num2) 
{
    if (num1 == num2) 
		return "0";
    
    // make sure: num1 >= num2
    if (num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2)) 
	{
        swap(num1, num2);
    }
    
    string res;
    int borrow = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    
    while (i >= 0) 
	{
        int digit1 = num1[i--] - '0' - borrow;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        
        borrow = 0;
        if (digit1 < digit2) 
		{
            digit1 += 10;
            borrow = 1;
        }
        
        res.push_back((digit1 - digit2) + '0');
    }
    
    //remove leading zero
    reverse(res.begin(), res.end());
    size_t startpos = res.find_first_not_of('0');
    if (startpos == string::npos) return "0";
    return res.substr(startpos);
}

// Karatsuba main function
string karatsuba(const string& x, const string& y) 
{
    if (x == "0" || y == "0") 	
		return "0";

    if (x.size() <= 2 && y.size() <= 2) 
	{
        return to_string(stoll(x) * stoll(y));
    }
    
    int n = max(x.size(), y.size());
    int m = (n + 1) / 2;  
    
    // fill zero to make euqal lengths
    string xp = string(n - x.size(), '0') + x;
    string yp = string(n - y.size(), '0') + y;
    
    //divide number
    string a = xp.substr(0, xp.size() - m);
    string b = xp.substr(xp.size() - m);
    string c = yp.substr(0, yp.size() - m);
    string d = yp.substr(yp.size() - m);
    

    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    
    // compute (a+b)(c+d)
    string a_plus_b = addStrings(a, b);
    string c_plus_d = addStrings(c, d);
    string ad_plus_bc = karatsuba(a_plus_b, c_plus_d);
    
    // compute ad+bc = (a+b)(c+d) - ac - bd
    ad_plus_bc = subtractStrings(ad_plus_bc, ac);
    ad_plus_bc = subtractStrings(ad_plus_bc, bd);
    
    // result：ac * 10^(2m) + (ad+bc) * 10^m + bd
    string term1 = ac + string(2 * m, '0');
    string term2 = ad_plus_bc + string(m, '0');
    string result = addStrings(addStrings(term1, term2), bd);
    
    return result;
}

int main() 
{
    string num1, num2;
    cout << "Please input the first large number: ";
    cin >> num1;
    cout << "Please input the second large number: ";
    cin >> num2;
    
    string result = karatsuba(num1, num2);
    cout << "Multiplication Result: " << result << endl;
    
//    // Samples:
//    cout << "\nSamples:\n";
//    cout << "1234 * 5678 = " << karatsuba("1234", "5678") << endl;  // 7006652
//    cout << "123 * 456 = " << karatsuba("123", "456") << endl;      // 56088
//    cout << "999 * 999 = " << karatsuba("999", "999") << endl;      // 998001
//    cout << "0 * 12345 = " << karatsuba("0", "12345") << endl;      // 0
//    
    return 0;
}