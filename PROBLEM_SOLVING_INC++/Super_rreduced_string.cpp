/*Reduce a string of lowercase characters in range ascii[‘a’..’z’]by doing a series of operations. In each operation, select a pair of adjacent letters that match, and delete them.

Delete as many characters as possible using this method and return the resulting string. If the final string is empty, return Empty String


Function Description

Complete the superReducedString function in the editor below.

superReducedString has the following parameter(s):

string s: a string to reduce
Returns

string: the reduced string or Empty String


Input Format

A single string, s.

Constraints

1  <=  len of s  <=  100


Sample Input 0

aaabccddd
Sample Output 0

abd*/

string superReducedString(string s) {
    string ch="";
    for(int i=0;i<s.length();i++)
    {
        if(ch.empty())
        {
            ch.push_back(s[i]);
        }
        else{
            if(s[i]==ch[ch.size()-1])
            ch.pop_back();
            else
            ch.push_back(s[i]);
        }
    }
    
    if(ch=="")
    return "Empty String";

    return ch;
}
