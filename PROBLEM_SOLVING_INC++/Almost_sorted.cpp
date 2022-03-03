/*Given an array of integers, determine whether the array can be sorted in ascending order using only one of the following operations one time.

Swap two elements.
Reverse one sub-segment.
Determine whether one, both or neither of the operations will complete the task. If both work, choose swap. For instance, given an array [2,3,5,4] either swap the 4 and 5, or reverse them to sort the array. Choose swap. The Output Format section below details requirements.

Function Description

Complete the almostSorted function in the editor below. It should print the results and return nothing.

almostSorted has the following parameter(s):

arr: an array of integers

Input Format

The first line contains a single integer n, the size of arr.
The next line contains n space-separated integers arr[i] where 1<=i<=n.

Output Format

If the array is already sorted, output yes on the first line. You do not need to output anything else.

2. If you can sort this array using one single operation (from the two permitted operations) then output yes on the first line and then:

a. If elements can be swapped,d[l] and d[r], output swap l r in the second line.l and r are the indices of the elements to be swapped, assuming that the array is indexed from 1 to n.

b. Otherwise, when reversing the segment d[l…r], output reverse l r in the second line.l and r are the indices of the first and last elements of the subsequence to be reversed, assuming that the array is indexed from 1 to n.

d[l…r] represents the sub-sequence of the array, beginning at index and ending at index , both inclusive.

If an array can be sorted by either swapping or reversing, choose swap.

If you cannot sort the array either way, output no on the first line.

Sample Input 1

2 
4 2
Sample Output 1

yes 
swap 1 2
Explanation 1

You can either swap(1, 2) or reverse(1, 2). You prefer swap.

Sample Input 2

3
3 1 2
Sample Output 2

no
Explanation 2

It is impossible to sort by one single operation.

Sample Input 3

6
1 5 4 3 2 6
Sample Output 3

yes
reverse 2 5
Explanation 3

You can reverse the sub-array d[2…5] = “5 4 3 2”, then the array becomes sorted.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



void almostSorted(vector<int> arr) {
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes" << endl;
        return;
    }
    int size = arr.size();
    int i = 0;
    int j = size - 1;
    
    for (; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            break;
        }
    }
    for (; j > 0; j--)
    {
        if (arr[j] < arr[j - 1])
        {
            break;
        }
    }

    
    swap(arr[i], arr[j]);
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes" << endl;
        cout << "swap " << i + 1 << " " << j + 1 << endl;
        return;
    }
    swap(arr[i], arr[j]);
    reverse(arr.begin() + i, arr.begin() + j + 1);
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes" << endl;
        cout << "reverse " << i + 1 << " " << j + 1 << endl;
        return;
    }

    cout << "no" << endl;
}

int main()
{
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

    almostSorted(arr);

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
