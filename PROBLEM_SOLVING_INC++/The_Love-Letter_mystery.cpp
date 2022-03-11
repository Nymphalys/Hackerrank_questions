/*James found a love letter that his friend Harry has written to his girlfriend. James is a prankster, so he decides to meddle with the letter. He changes all the words in the letter into palindromes.

To do this, he follows two rules:

1. He can only reduce the value of a letter by 1, i.e. he can change d to c, but he cannot change c to d or d to b.
2. The letter  a may not be reduced any further.

Each reduction in the value of any letter is counted as a single operation. Find the minimum number of operations required to convert a given string into a palindrome.


Function Description

Complete the theLoveLetterMystery function in the editor below.

theLoveLetterMystery has the following parameter(s):

string s: the text of the letter

Returns

int: the minimum number of operations


Input Format

The first line contains an integer q, the number of queries.
The next q  lines will each contain a string s.


Constraints

1  <=  q  <=  10

1  <=   | s |   <=  10^4
All strings are composed of lower case English letters, ascii[a-z], with no spaces.
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int theLoveLetterMystery(string s) {
    int count = 0;
    for(int i = 0; i < s.length()/2; i++)
      count += abs(s[i] - s[s.length() - 1 - i]);
    return count;
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

        int result = theLoveLetterMystery(s);

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
