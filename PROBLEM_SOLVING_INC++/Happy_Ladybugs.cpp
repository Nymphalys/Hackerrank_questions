/*Happy Ladybugs is a board game having the following properties:

The board is represented by a string, b, of length n. The ith character of the string,b[i] , denotes ith the cell of the board.

If b[i] is an underscore (i.e., _), it means the ith cell of the board is empty.

If b[i] is an uppercase English alphabetic letter (ascii[A-Z]), it means the ith cell contains a ladybug of color b[i].
String b will not contain any other characters.

A ladybug is happy only when its left or right adjacent cell (i.e.,b[i+1] ) is occupied by another ladybug having the same color.

In a single move, you can move a ladybug from its current position to any empty cell.

Given the values of n and b for games of Happy Ladybugs, determine if it’s possible to make all the ladybugs happy. For each game, print YES on a new line if all the ladybugs can be made happy through some number of moves. Otherwise, print NO.

As an example,b=[YYR_B_BR] . You can move the rightmost B and R to make b=[YYRRBB_] and all the ladybugs are happy.

Function Description

Complete the happyLadybugs function in the editor below. It should return an array of strings, either ‘YES’ or ‘NO’, one for each test string.

happyLadybugs has the following parameters:

b: an array of strings that represents the initial positions and colors of the ladybugs

Input Format

The first line contains an integer g, the number of games.

The next g pairs of lines are in the following format:

The first line contains an integer n, the number of cells on the board.
The second line contains a string b describing the n cells of the board.
Constraints

Output Format

For each game, print YES on a new line if it is possible to make all the ladybugs happy. Otherwise, print NO.

Sample Input 0

4
7
RBY_YBR
6
X_Y__X
2
__
6
B_RRBR
Sample Output 0

YES
NO
YES
YES*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


string happyLadybugs(string b) {
    int l=count(b.begin(), b.end(), '_');
    int ans1=0,ans2=0, n=b.size();
    if(l==0){
        for(int i=0; i<n-l; i++){
            if(b[i]==b[i-1] || b[i]==b[i+1]) ans2++;
        }
    if(ans2==n) return "YES";
    else return "NO";
    }
    sort(b.begin(),b.end());
    for(int i=0; i<n-l; i++){
        if(b[i]==b[i-1] || b[i]==b[i+1]) ans1++;
    }
    if( ans1==n-l) return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

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
