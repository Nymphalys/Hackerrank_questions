/*Problem Statement :

Sorting is useful as the first step in many different tasks. The most common task is to make finding things easier, but there are other uses as well. In this case, it will make it easier to determine which pair or pairs of elements have the smallest absolute difference between them.


Note
As shown in the example, pairs may overlap.

Given a list of unsorted integers, arr , find the pair of elements that have the smallest absolute difference between them. If there are multiple pairs, find them all.

Function Description

Complete the closestNumbers function in the editor below.

closestNumbers has the following parameter(s):

int arr[n]: an array of integers
Returns
- int[]: an array of integers as described

Input Format

The first line contains a single integer n, the length of arr.
The second line contains n  space-separated integers, arr[i].


*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


vector<int> closestNumbers(vector<int> arr) {
    vector<int> o;
    int buffdiff = 100000001;
    sort(arr.begin(), arr.end());
    for(int i = 1; i < arr.size(); i++){
        if(abs(arr[i] - arr[i-1]) < buffdiff){
            o.clear();
            o.push_back(arr[i-1]);
            o.push_back(arr[i]);
            buffdiff = abs(arr[i] - arr[i-1]);
        } 
        else if(abs(arr[i] - arr[i-1]) == buffdiff){
            o.push_back(arr[i-1]);
            o.push_back(arr[i]);
        } 
    }
    return o;
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

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
