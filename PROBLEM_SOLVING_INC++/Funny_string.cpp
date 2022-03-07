/*In this challenge, you will determine whether a string is funny or not. To determine whether a string is funny, create a copy of the string in reverse e.g.abc->cba . Iterating through each string, compare the absolute difference in the ascii values of the characters at positions 0 and 1, 1 and 2 and so on to the end. If the list of absolute differences is the same for both strings, they are funny.

Determine whether a give string is funny. If it is, return Funny, otherwise return Not Funny.

Example

s=’lmnop’

The ordinal values of the charcters are [108,109,110,111,112]. S reverse=’ponml’ and the ordinals are [112,111,110,109,108]. The absolute differences of the adjacent elements for both strings are [1,1,1,1], so the answer is Funny.

Function Description

Complete the funnyString function in the editor below.

funnyString has the following parameter(s):

string s: a string to test
Returns

string: either Funny or Not Funny
Input Format

The first line contains an integer q, the number of queries.

The next q lines each contain a string,s .

Constraints

1<=q<=10
2<=length of s<=10000
Sample Input

STDIN   Function

-----   --------

2       q = 2

acxz    s = 'acxz'

bcxz    s = 'bcxz'
 

Sample Output

Funny

Not Funny*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


string funnyString(string s) {
int i=0,j=s.size()-1;
    while(i<=j)
    {
        if(abs(s[i]-s[i+1])!=abs(s[j]-s[j-1]))
        return "Not Funny";
        i++;j--;
    }
    return "Funny";
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

        string result = funnyString(s);

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
