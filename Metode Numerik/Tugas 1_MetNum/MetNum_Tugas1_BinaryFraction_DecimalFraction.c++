// C++ program to demonstrate above steps of
// binary fractional to decimal conversion
#include<bits/stdc++.h>
using namespace std;
 
// Function to convert binary fractional to
// decimal
double binaryToDecimal(string binary, int len)
{
    // Fetch the radix point
    size_t point = binary.find('.');
 
    // Update point if not found
    if (point == string::npos)
        point = len;
 
    double intDecimal = 0, fracDecimal = 0, twos = 1;
 
    // Convert integral part of binary to decimal
    // equivalent
    for (int i = point-1; i>=0; --i)
    {
        // Subtract '0' to convert character
        // into integer
        intDecimal += (binary[i] - '0') * twos;
        twos *= 2;
    }
 
    // Convert fractional part of binary to
    // decimal equivalent
    twos = 2;
    for (int i = point+1; i < len; ++i)
    {
        fracDecimal += (binary[i] - '0') / twos;
        twos *= 2.0;
    }
 
    // Add both integral and fractional part
    return intDecimal + fracDecimal;
}
 
// Driver code
int main()
{
    string n = "110.101";
    cout << binaryToDecimal(n, n.length()) << "\n";
 
    n = "101.1101";
    cout << binaryToDecimal(n, n.length());
 
    return 0;
}

