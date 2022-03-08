/*The previous challenges covered Insertion Sort, which is a simple and intuitive sorting algorithm with a running time of O(n^2). In these next few challenges, we’re covering a divide-and-conquer algorithm called Quicksort (also known as Partition Sort). This challenge is a modified version of the algorithm that only addresses partitioning. It is implemented as follows:

Step 1: Divide

Choose some pivot element,p, and partition your unsorted array, arr, into three smaller arrays: left,right , and equal, where each element in left<p, each element in right>p, and each element in equal=p.

For example: Assume arr=[5,7,4,3,8] 

The pivot is at arr[0] = 5
 is divided into left ,equal , and right .

Function Description

Complete the quickSort function in the editor below. It should return an array of integers as described above.

quickSort has the following parameter(s):

arr: an array of integers where arr[0] is the pivot element
Input Format

The first line contains n, the size of the array arr.

The second line contains n space-separated integers describing arr (the unsorted array). The first integer (corresponding to arr[0]) is your pivot element, p.

Constraints

1<=n<=1000
1000<=arr[i]<=1000 where 0<=i<=n 
All elements will be unique.
Output Format

On a single line, print the partitioned numbers (i.e.: the elements in left, then the elements in equal, and then the elements in right). Each integer should be separated by a single space.

Sample Input

5

4 5 3 7 2


Sample Output

3 2 4 5 7*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



vector<int> quickSort(vector<int> arr) {
    vector<int> left, right, equal, result;

    for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        if(*it > arr[0])
            right.push_back(*it);
        else if(*it < arr[0])
            left.push_back(*it);
        else
            equal.push_back(*it);
    }

    for(vector<int>::iterator it = left.begin(); it != left.end(); ++it)
        result.push_back(*it);

    for(vector<int>::iterator it = equal.begin(); it != equal.end(); ++it)
        result.push_back(*it);

    for(vector<int>::iterator it = right.begin(); it != right.end(); ++it)
        result.push_back(*it);

    return result;
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

    vector<int> result = quickSort(arr);

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
