/*You are given a number of sticks of varying lengths. You will iteratively cut the sticks into smaller sticks, discarding the shortest pieces until there are none left. At each iteration you will determine the length of the shortest stick remaining, cut that length from each of the longer sticks and then discard all the pieces of that shortest length. When all the remaining sticks are the same length, they cannot be shortened so discard them.

Given the lengths of n sticks, print the number of sticks that are left before each iteration until there are none left.

Example

arr = [1,2,3]

The shortest stick length is 1, so cut that length from the longer two and discard the pieces of length 1. Now the lengths are arr=[1,2]. Again, the shortest stick is of length 1, so cut that amount from the longer stick and discard those pieces. There is only one stick left,arr=[1] , so discard that stick. The number of sticks at each iteration are answer=[3,2,1].

Function Description

Complete the cutTheSticks function in the editor below. It should return an array of integers representing the number of sticks before each cut operation is performed.

cutTheSticks has the following parameter(s):

int arr[n]: the lengths of each stick
Returns

int[]: the number of sticks after each iteration
Input Format

The first line contains a single integer , the size of .

The next line contains  space-separated integers, each an , where each value represents the length of the  stick.

Constraints

1<=n<=1000
1<=arr[i]<=1000
Sample Input 0

STDIN           Function

-----           --------

6               arr[] size n = 6

5 4 4 2 2 8     arr = [5, 4, 4, 2, 2, 8]
 

Sample Output 0

6

4

2

1


Explanation 0

sticks-length        length-of-cut   sticks-cut

5 4 4 2 2 8             2               6

3 2 2 _ _ 6             2               4

1 _ _ _ _ 4             1               2

_ _ _ _ _ 3             3               1

_ _ _ _ _ _           DONE            DONE
 

Sample Input 1

8

1 2 3 4 3 3 2 1


Sample Output 1

8

6

4

1


Explanation 1

sticks-length         length-of-cut   sticks-cut

1 2 3 4 3 3 2 1         1               8

_ 1 2 3 2 2 1 _         1               6

_ _ 1 2 1 1 _ _         1               4

_ _ _ 1 _ _ _ _         1               1

_ _ _ _ _ _ _ _       DONE            DONE*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> cutTheSticks(vector<int> arr) {
    vector<int>ans;
    ans.push_back(arr.size());
    sort(arr.begin(),arr.end());
    while(arr.size()){
        vector<int>::iterator it;
        it=upper_bound(arr.begin(),arr.end(),arr[0]);
        arr.erase(arr.begin(),it);
        if(arr.size())ans.push_back(arr.size());
    }
    return ans;
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

    vector<int> result = cutTheSticks(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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
