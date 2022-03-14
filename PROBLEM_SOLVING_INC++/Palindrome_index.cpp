/*Given a string of lowercase letters in the range ascii[a-z], determine the index of a character that can be removed to make the string a palindrome. There may be more than one solution, but any will do. If the word is already a palindrome or there is no solution, return -1. Otherwise, return the index of a character to remove.

Example

s = "bcbc"

Either remove 'b' at index 0 or 'c' at index 3.


Function Description

Complete the palindromeIndex function in the editor below.

palindromeIndex has the following parameter(s):

string s: a string to analyze

Returns

int: the index of the character to remove or -1.

Input Format

The first line contains an integer q, the number of queries.
Each of the next q lines contains a query string s.



Constraints

1  <=   q  <= 20
1  <=   length of s  <=  10^5 + 5 


All characters are in the range ascii[a-z].
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int palindromeIndex(string s) {
    int n=s.length(),x,y;
    for(int i=0,j=n-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            string s1=s;
            s1.erase(s1.begin()+i);
            for(x=0,y=n-2;x<y;x++,y--){
             if(s1[x]!=s1[y])
                 break;             
            }
            if(x>=y)        
            return i;            
            string s2=s;
            s2.erase(s2.begin()+j);
            for(x=0,y=n-2;x<y;x++,y--){
             if(s2[x]!=s2[y])
                 break;                
            }         
            if(x>=y)        
            return j;
            else
            return -1;
        }
    }
    return -1;    
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

        int result = palindromeIndex(s);

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
