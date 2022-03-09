/*Dothraki are planning an attack to usurp King Robert's throne. King Robert learns of this conspiracy from Raven and plans to lock the single door through which the enemy can enter his kingdom.

But, to lock the door he needs a key that is an anagram of a palindrome. He starts to go through his box of strings, checking to see if they can be rearranged into a palindrome. Given a string, determine if it can be rearranged into a palindrome. Return the string YES or NO.

Example

s = 'aabbccdd'

One way this can be arranged into a palindrome is aabbccdd. Return YES.

Function Description

Complete the gameOfThrones function below.

gameOfThrones has the following parameter(s):

string s: a string to analyze



Returns

string: either YES or NO


Input Format

A single line which contains s.

Constraints

1  <=   |s|   <=  10^5
s contains only lowercase letters in the range ascii[a . . . z ]*/

#include <bits/stdc++.h>

using namespace std;



string gameOfThrones(string s) {
vector<int> f(26,0);
for(int i=0;i<s.size();i++)
{
    f[s[i]-'a']++;
}
int count1=0;
for(int i=0;i<26;i++)
{
    if(f[i]%2!=0&&count1==1)
    return "NO";
    if(f[i]%2!=0)
    count1++;
}
return "YES";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}


