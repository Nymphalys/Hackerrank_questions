/*A student is taking a cryptography class and has found anagrams to be very useful. Two strings are anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency. For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

The student decides on an encryption scheme that involves two large strings. The encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Determine this number.

Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character deletions required to make a and b anagrams. Any characters can be deleted from either of the strings.



Function Description

Complete the makeAnagram function in the editor below.

makeAnagram has the following parameter(s):

string a: a string
string b: another string
Returns

int: the minimum total characters that must be deleted
Input Format

The first line contains a single string, a.
The second line contains a single string, b.

Constraints

1  <=  | a |, | b |  <= 10^4
The strings a and b consist of lowercase English alphabetic letters, ascii[a-z].
*/
#include <bits/stdc++.h>

using namespace std;


int makingAnagrams(string s1, string s2) 
{
    vector<int> freq1(26);vector<int> freq2(26);
    int count=0;
    for(int i=0;i<s1.size();i++)freq1[s1[i]-'a']++;
    for(int i=0;i<s2.size();i++)freq2[s2[i]-'a']++;
    for(int i=0;i<26;i++)count+=(max(freq1[i],freq2[i])-min(freq1[i],freq2[i]));
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
