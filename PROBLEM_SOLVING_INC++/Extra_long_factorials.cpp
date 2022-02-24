/*The factorial of the integer n, written n!, is defined as:

Calculate and print the factorial of a given integer.

For example, if n=30, we calculate 30*29*28*….*2*1 and get .

Function Description

Complete the extraLongFactorials function in the editor below. It should print the result and return.
extraLongFactorials has the following parameter(s):

n: an integer

Note: Factorials of n>20 can’t be stored even in a 64-bit long long variable. Big integers must be used for such calculations. Languages like Java, Python, Ruby etc. can handle big integers, but we need to write additional code in C/C++ to handle huge values.

We recommend solving this challenge using BigIntegers.

Input Format

Input consists of a single integer n

Constraints

1<=n<=100

Output Format

Print the factorial of n.

Sample Input

25*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void extraLongFactorials(int n) {
    vector<int> v(200, 0);
    int c=0, k=0;
    v[0]=1;
    for (int i=2;i<=n;i++)
    {
        for (int j=0;j<=k;j++)
        {
            v[j] = v[j]*i+c;
            c = v[j]/10;
            v[j]%=10;
        }
        while(c)
        {
            k++;
            v[k]=c%10;
            c/=10;
        }
    }
    for (int i=k;i>=0;i--)
        cout << v[i];
    return;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

