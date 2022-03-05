/*There is a sequence of words in CamelCase as a string of letters,s, having the following properties:

It is a concatenation of one or more words consisting of English letters.
All letters in the first word are lowercase.
For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.
Given s, determine the number of words in s.

Example

s = oneTwoThree

There are 3 words in the string: ‘one’, ‘Two’, ‘Three’.
Function Description

Complete the camelcase function in the editor below.

camelcase has the following parameter(s):

string s: the string to analyze
Returns

int: the number of words in s
Input Format

A single line containing string s.

Constraints

1<=length of s<=10^5
Sample Input

saveChangesInTheEditor
 

Sample Output

5*/
#include <bits/stdc++.h>

using namespace std;



int camelcase(string s) {
  int word=0;
  for(int i=0;i<s.length();i++) if(isupper(s[i])==256) word++;
  (s.length()==0)?word=0:word++;
  return word;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
