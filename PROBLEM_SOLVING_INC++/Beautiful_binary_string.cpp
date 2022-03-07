/*Alice has a binary string. She thinks a binary string is beautiful if and only if it doesn’t contain the substring “010”.

In one step, Alice can change a 0 to a 1 or vice versa. Count and print the minimum number of steps needed to make Alice see the string as beautiful.

For example, if Alice’s string is b=010 she can change any one element and have a beautiful string.

Function Description

Complete the beautifulBinaryString function in the editor below. It should return an integer representing the minimum moves required.

beautifulBinaryString has the following parameter(s):

b: a string of binary digits
Input Format

The first line contains an integer , the length of binary string.

The second line contains a single binary string .

Constraints

1<=n<=100
.b[i] belongs to {0,1}
Output Format

Print the minimum number of steps needed to make the string beautiful.

Sample Input 0

7

0101010
 

Sample Output 0

2  */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int beautifulBinaryString(string b) {

string temp = "010";
int count = 0;
for (int i = 0 ; (unsigned) i + 3  <= b.size() ; i++)
{
    string s = b.substr(i,3);
    cout << s  << endl;
    if (s == temp)
    {
        count ++;
        i = i + 2;
    }
}
return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

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
