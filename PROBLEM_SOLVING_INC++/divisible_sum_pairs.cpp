/*You are given an array of n integers,ar=ar[0],ar[1],…,ar[n-1] , and a positive integer,k . Find and print the number of (i,j) pairs where i<j and ar[i] + ar[j] is divisible by .

For example,ar = [1,2,3,4,5,6]  and k=5. Our three pairs meeting the criteria are [1,4],[2,3] and [4,6].

Function Description

Complete the divisibleSumPairs function in the editor below. It should return the integer count of pairs meeting the criteria.

divisibleSumPairs has the following parameter(s):
n: the integer length of array ar
ar: an array of integers
k: the integer to divide the pair sum by
Input Format

The first line contains 2 space-separated integers,n  and k.

The second line contains n space-separated integers describing the values of ar[ar[0],ar[1],….,ar[n-1]].

Constraints

2<=n<=100
1<=k<=100
1<=ar[i]<=100
Output Format

Print the number of (i,j) pairs where i<j and  a[i]+a[j]  is evenly divisible by k.

Sample Input

6 3

1 3 2 6 1 2
Sample Output

5
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count = 0;
    for (auto it = begin(ar); it != end(ar); ++it) {
        int value = *it;
        count += count_if(next(it), end(ar), [k,value](int value2) {
            return (value + value2) % k == 0;
        });
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = divisibleSumPairs(n, k, ar);

    fout << result << "\n";

    fout.close();

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
