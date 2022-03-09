/*Given two strings, determine if they share a common substring. A substring may be as small as one character.

Example

s1 = 'and'
s2  = 'art'


These share the common substring a.

s1 = 'be'
s2 = 'cat'


These do not share a substring.

Function Description

Complete the function twoStrings in the editor below.

twoStrings has the following parameter(s):

string s1: a string
string s2: another string

Returns

string: either YES or NO

Input Format

The first line contains a single integer p, the number of test cases.

The following p pairs of lines are as follows:

The first line contains string s1.
The second line contains string s2.


Constraints

s1 and s2 consist of characters in the range ascii[a-z].
1  <=  p  <= 10
1  <=  | s1 |, | s2 |  <= 10^5

Output Format

For each pair of strings, return YES or NO.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



string twoStrings(string s1, string s2) 
{
    int cc[26]={0}, i=0;
    
    while(s1[i]) cc[s1[i++]-'a']++;
    
    i=0;
    while(s2[i]) if(cc[s2[i++]-'a']) return "YES";
    
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

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
