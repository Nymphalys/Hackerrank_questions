/*Sorting is useful as the first step in many different tasks. The most common task is to make finding things easier, but there are other uses as well. In this case, it will make it easier to determine which pair or pairs of elements have the smallest absolute difference between them.

Example

arr=[5,2,3,4,1]

Sorted,arr’=[1,2,3,4,5] . Several pairs have the minimum difference of 1:[(1,2),(2,3),(3,4),(4,5)} . Return the array [1,2,2,3,3,4,4,5].

Note

As shown in the example, pairs may overlap.

Given a list of unsorted integers,arr , find the pair of elements that have the smallest absolute difference between them. If there are multiple pairs, find them all.

Function Description

Complete the closestNumbers function in the editor below.

closestNumbers has the following parameter(s):

int arr[n]: an array of integers
Returns

– int[]: an array of integers as described

Input Format

The first line contains a single integer n, the length of arr.

The second line contains n space-separated integers, arr[i].

Constraints

2<=n<=200000
-10^7<=arr[i]<=10^7
All a[i] are unique in arr.
Output Format

Sample Input 0

10

-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 
 

Sample Output 0

-20 30
 

Explanation 0

(30) – (-20) = 50, which is the smallest difference.

Sample Input 1

12

-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 -520 -470 
 

Sample Output 1

-520 -470 -20 30
 

Explanation 1

(-470) – (-520) = 30 – (-20) = 50, which is the smallest difference.*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int findMedian(vector<int> arr) {
sort(arr.begin(),arr.end());
int t=arr.size()/2;
return (arr[t]);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = findMedian(arr);

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
