/*We say that a string contains the word hackerrank if a subsequence of its characters spell the word hackerrank. Remember that a subsequence maintains the order of characters selected from a sequence.

More formally, let p[0],p[1],…p[9] be the respective indices of h, a, c, k, e, r, r, a, n, k in string . If p[0]<p[1]<p[2]<…p[9] is true, then s contains hackerrank.

For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO.

Example

s=haacckkerrannkk

This contains a subsequence of all of the characters in the proper order. Answer YES

s=haacckkerannk

This is missing the second ‘r’. Answer NO.

s=hccaakkerrannkk

There is no ‘c’ after the first occurrence of an ‘a’, so answer NO.

Function Description

Complete the hackerrankInString function in the editor below.

hackerrankInString has the following parameter(s):

string s: a string
Returns

string: YES or NO
Input Format

The first line contains an integer , the number of queries.

Each of the next  lines contains a single query string .

Constraints

1<=q<=10^2
10<=length of s<=10^4
Sample Input 0

2

hereiamstackerrank

hackerworld


Sample Output 0

YES

NO
 

Explanation 0

We perform the following  queries:

s=hereiamstackerrank
The characters of hackerrank are bolded in the string above. Because the string contains all the characters in hackerrank in the same exact order as they appear in hackerrank, we return YES.
s=hackerworld does not contain the last three characters of hackerrank, so we return NO.
Sample Input 1

2

hhaacckkekraraannk

rhbaasdndfsdskgbfefdbrsdfhuyatrjtcrtyytktjjt
 

Sample Output 1

YES

NO*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



string hackerrankInString(string s) {
    int i = 0;
    int cnt = 0;
    string ori = "hackerrank";
    for (int j = 0; j < s.size(); j++) {
        if (ori[i] == s[j]) {
            i++;
            cnt++;
        } 
    }
    return cnt == 10 ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

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
