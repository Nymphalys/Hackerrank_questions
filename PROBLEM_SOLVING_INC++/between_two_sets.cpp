/*You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:
The elements of the first array are all factors of the integer being considered
The integer being considered is a factor of all elements of the second array
These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.
For example, given the arrays a =[2, 6] and b = [24, 36], there are two numbers between them: 6 and 12 . 6 % 2 = 0 , 6 % 6 = 0 , 24 % 6 = 0 and 36 % 6 = 0 for the first value. Similarly 12 % 6 = 0 and 24 % 12 = 0 , 36 % 12 = 0.
Function Description
Complete the getTotalX function in the editor below. It should return the number of integers that are between the sets.
getTotalX has the following parameter(s):
a: an array of integers
b: an array of integers
Input Format
The first line contains two space-separated integers, n, and m, the number of elements in the array a and the number of elements in the array b.
The second line contains n distinct space-separated integers describing a[i] where 0 ≤ i <n.
The third line contains distinct space-separated integers describing b[j] where 0 ≤ j < m.
Output Format
Print the number of integers that are considered to be between a and b.
Sample Input
2 3
2 4
16 32 96
Sample Output
3
Explanation
2 and 4 divide evenly into 4, 8, 12 and 16.
4, 8 and 16 divide evenly into 16, 32, 96.
4, 8 and 16 are the only three numbers for which each element of a is a factor and each is a factor of all elements of b. */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int getTotalX(vector<int> a, vector<int> b) {
      
    std::vector<int> arr;
    int num = 1;
   
    while (num <= 100) {
        int ctr1 = 0;
        int ctr2 = 0;
        
        for (int i = 0; i <  a.size(); i++) {
            if (num % a[i] == 0) {
                ctr1++;
            }
        
        }
        for (int i = 0; i <  b.size(); i++) {
            if (b[i] % num == 0) {
                ctr2++;
            }
        }
        if (ctr1 == a.size() && ctr2 == b.size()) {
            arr.push_back(num);
        }
        num++;
    }
    return arr.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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
