/*Amanda has a string of lowercase letters that she wants to copy to a new string. She can perform the following operations with the given costs. She can perform them any number of times to construct a new string p:
Append a character to the end of string p at a cost of 1 dollar.
Choose any substring of p and append it to the end of p at no charge.
Given n strings s[i], find and print the minimum cost of copying each s[i]to p[i]on a new line.
For example, given a string s=“abcabc”, it can be copied for 3 dollars. Start by copying ‘a’, ‘b’, and ‘c’ individually at a cost of 1 dollar per character. String p = ‘abc’ at this time. Copy p[0:2]to the end of p at no cost to complete the copy.
Function Description
Complete the stringConstruction function in the editor below. It should return the minimum cost of copying a string.
stringConstruction has the following parameter(s):
s: a string
Input Format
The first line contains a single integer n, the number of strings.
Each of the next n lines contains a single string, s[i].
Constraints
1 ≤ n ≤ 5
1≤|s[i]|≤10⁵
Subtasks
1≤|s[i]|≤ 10³ for 45% of the maximum score.
Output Format
For each string s[i]print the minimum cost of constructing a new string p[i]on a new line.
Sample Input
2
abcd
abab
Sample Output
4
2*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int stringConstruction(string s) {
    
    map<char,int> mp;
    int cost=0;
    for(int i=0;i<s.length();i++)
    {
        if(mp[s[i]]==0)
        {
            cost+=1;
            mp[s[i]]=1;
            
        }       
    }
    return cost;
    

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

        int result = stringConstruction(s);

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
