/*Use the counting sort to order a list of strings associated with integers. If two strings are associated with the same integer, they must be printed in their original order, i.e. your sorting algorithm should be stable. There is one other twist: strings in the first half of the array are to be replaced with the character - (dash, ascii 45 decimal).

Insertion Sort and the simple version of Quicksort are stable, but the faster in-place version of Quicksort is not since it scrambles around elements while sorting.

Design your counting sort to be stable.


Function Description

Complete the countSort function in the editor below. It should construct and print the sorted strings.

countSort has the following parameter(s):

string arr[n][2]: each arr[i] is comprised of two strings, x and s
Returns
- Print the finished array with each element separated by a single space.

Note: The first element of each , , must be cast as an integer to perform the sort.

Input Format

The first line contains , the number of integer/string pairs in the array .
Each of the next  contains  and , the integers (as strings) with their associated strings.


Output Format

Print the strings in their correct order, space-separated on one line.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



void countSort(vector<vector<string>> arr) {
    
    multimap<int,string> m;

    for(int i = 0 ; i<arr.size()/2 ; i++)
        arr[i][1] = "-";

    for(auto a : arr)
        m.insert(make_pair(stoi(a[0]),a[1]));

    for(auto itr : m)
        cout<< itr.second + " ";

}
int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

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
