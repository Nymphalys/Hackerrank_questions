/*A pangram is a string that contains every letter of the alphabet. Given a sentence determine whether it is a pangram in the English alphabet. Ignore case. Return either pangram or not pangram as appropriate.

Example

s = ‘The quick brown fox jumps over lazy dog’ 

The string contains all letters in the English alphabet, so return pangram.

Function Description

Complete the function pangrams in the editor below. It should return the string pangram if the input string is a pangram. Otherwise, it should return not pangram.

pangrams has the following parameter(s):

string s: a string to test
Returns

string: either pangram or not pangram
Input Format

A single line with string .

Constraints

0<= length of s <= 10^3

Sample Input

Sample Input 0

We promptly judged antique ivory buckles for the next prize
Sample Output 0

pangram
Sample Explanation 0

All of the letters of the alphabet are present in the string.
Sample Input 1

We promptly judged antique ivory buckles for the prize
Sample Output 1

not pangram
Sample Explanation 0

The string lacks an x.*/

#include <bits/stdc++.h>

using namespace std;

string pangrams(string s) {

vector<bool> mark(26, false);
int ind;

string ans="pangram";

for(int i=0;i<s.length();i++)
{
    if(s[i]>='A' && s[i]<='Z')
    {
        ind=s[i]-'A';
        mark[ind] = true;
    }
    else if(s[i]>='a' && s[i]<='z')
    {
        ind=s[i]-'a';
        mark[ind]=true;
    }
}
for(int i=0;i<26;i++)
{
    if(mark[i]==false)
    {
        ans="not pangram";
    }
}

return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
