/*Lexicographical order is often known as alphabetical order when dealing with strings. A string is greater than another string if it comes later in a lexicographically sorted list.

Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria:

It must be greater than the original word
It must be the smallest word that meets the first condition
Example

The next largest word is .

Complete the function biggerIsGreater below to create and return the new string meeting the criteria. If it is not possible, return no answer.

Function Description

Complete the biggerIsGreater function in the editor below.

biggerIsGreater has the following parameter(s):

string w: a word
Returns
- string: the smallest lexicographically higher string possible or no answer

Input Format

The first line of input contains , the number of test cases.
Each of the next  lines contains .

Constraints

 will contain only letters in the range ascii[a..z].
Sample Input 0

5
ab
bb
hefg
dhck
dkhc
Sample Output 0

ba
no answer
hegf
dhkc
hcdk
Explanation 0

Test case 1:
ba is the only string which can be made by rearranging ab. It is greater.
Test case 2:
It is not possible to rearrange bb and get a greater string.
Test case 3:
hegf is the next string greater than hefg.
Test case 4:
dhkc is the next string greater than dhck.
Test case 5:
hcdk is the next string greater than dkhc.
Sample Input 1

6
lmno
dcba
dcbb
abdc
abcd
fedcbabcd
Sample Output 1

lmon
no answer
no answer
acbd
abdc
fedcbabdc*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string biggerIsGreater(string w) {

   
    return (next_permutation(w.begin(), w.end())) ? w : "no answer";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

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

