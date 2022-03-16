/*Palindromes are strings that read the same from the left or right, for example madam or 0110.

You will be given a string representation of a number and a maximum number of changes you can make.  Alter the string, one digit at a time, to create the string representation of the largest number possible given the limit to the number of changes.  The length of the string may not be altered, so you must consider 's left of all higher digits in your tests.  For example  is valid,  is not.

Given a string representing the starting number and a maximum number of changes allowed, create the largest palindromic string of digits possible or the string -1 if it's impossible to create a palindrome under the contstraints.

Function Description

Complete the highestValuePalindrome function in the editor below.  It should return a string representing the largest value palindrome achievable, or -1.

highestValuePalindrome has the following parameter(s):

s: a string representation of an integer
n: an integer that represents the length of the integer string
k: an integer that represents the maximum number of changes allowed
The first line contains two space-separated integers,  and , the number of digits in the number and the maximum number of changes allowed.
The second line contains an -digit string of numbers.

Each character  in the number is an integer where .
Print a single line with the largest number that can be made by changing no more than  digits. If this is not possible, print -1.

Sample Input 0

4 1
3943
Sample Output 0

3993
Sample Input 1

6 3
092282
Sample Output 1

992299
Sample Input 2

4 1
0011
Sample Output 2

-1
Sample 0

There are two ways to make  a palindrome by changing no more than  digits:

, so we print .*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


string highestValuePalindrome(string s, int n, int k){

    int i = 0, j = n - 1, count = 0;
    string visited = s;
    while (i < j) {
        if (s[i] < s[j]) {
            s[i] = s[j];
            visited[i] = 'x';
            count++;
        } else if (s[i] > s[j]) {
            s[j] = s[i];
            visited[j] = 'x';
            count++;
        }
        i++;
        j--;
    }
    int z = k - count;
    if (z <= 0) return z < 0 ? "-1" : s;
    
    i = 0; j = n - 1;
    while (z > 0 && i < j) {
        if (s[i] != '9') {
          if (visited[i] == 'x' || visited[j] == 'x' || z > 1) {
            s[i] = '9';
            s[j] = '9';
            z -= (visited[i] == 'x' || visited[j] == 'x') ? 1 : 2;
          }
        }
        i++;
        j--;
    }
    if(z > 0 && n % 2 != 0) s[n/2] = '9';
    return s;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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
