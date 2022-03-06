/*Given a string, remove characters until the string is made up of any two alternating characters. When you choose a character to remove, all instances of that character must be removed. Determine the longest string possible that contains just two alternating letters.

**Example88.

$s = \text{abaacdabd}$

Delete a, to leave bcdbd. Now, remove the character c to leave the valid string bdbd with a length of 4. Removing either b or d at any point would not result in a valid string.

Given a string $s$, convert it to the longest possible string $t$ made up only of alternating characters. Print the length of string $t$ on a new line. If no string $t$ can be formed, print $0$ instead.

Function Description

Complete the alternate function in the editor below.

alternate has the following parameter(s):

string s: a string
Returns.

int: the length of the longest valid string, or $0$ if there are none
Input Format

The first line contains a single integer that denotes the length of s.

The second line contains string s.

Constraints

1<=lengthofs<=1000
S[i] belongs to ascii[a-z]
Sample Input

10

beabeefeab
 

Sample Output

5
 

Explanation

The characters present in s are a, b, e, and f. This means that t must consist of two of those characters and we must delete two others. Our choices for characters to leave are [a,b], [a,e], [a, f], [b, e], [b, f] and [e, f].

If we delete e and f, the resulting string is babab. This is a valid t as there are only two distinct characters (a and b), and they are alternating within the string.

If we delete a and f, the resulting string is bebeeeb. This is not a valid string t because there are consecutive e’s present. Removing them would leave consecutive b’s, so this fails to produce a valid string t.

Other cases are solved similarly.

babab is the longest string we can create.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int alternate(string s) {

int res = 0;

map<char,int> mp;
for(auto x : s){
    mp[x]++;
}

vector<char> c;
for(auto x : mp)
    c.push_back(x.first);

for(auto x : c)
    cout<<x<<" ";

for(int i = 0 ; i < c.size()-1 ; i++){
    for(int k = i+1 ; k < c.size() ; k++){
    char a = c[i];
    char b = c[k];

    string reff = "";

    for(auto x : s)
        if(x==a||x==b)
            reff+=x;

    bool flag = true;
    for(int j = 1 ; j < reff.size(); j++){
        if(reff[j]==reff[j-1] ){
            flag = false;
            break;
    }
    }

    int y = reff.size();
    if(flag)
        res = max(res,y);

}
}


return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

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
