/*A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string. Given two strings of equal length, what's the longest string that can be constructed such that it is a child of both?

For example, ABCD and ABDC have two children with maximum length 3, ABC and ABD. They can be formed by eliminating either the D or C from both strings. Note that we will not consider ABCD as a common child because we can't rearrange characters and ABCD  ABDC.

Function Description

Complete the commonChild function in the editor below. It should return the longest string which is a common child of the input strings.

commonChild has the following parameter(s):

s1, s2: two equal length strings
Input Format

There is one line with two space-separated strings, s1 and s2.

Constraints

1  <=   | s1 | , | s2 |  <=  5000
All characters are upper case in the range ascii[A-Z].
Output Format

Print the length of the longest string s, such that  is a child of both s1 and s2.
*/
#include <bits/stdc++.h>

using namespace std;



int commonChild(string s1, string s2) {
    int size1 = s1.size();
    int size2 = s2.size();
    vector<vector<int>> mat(size1 + 1, vector<int>(size2 +1, 0));

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(s1[i] == s2[j]) mat[i+1][j+1] = 1 + mat[i][j];
            else mat[i+1][j+1] = max(mat[i+1][j], mat[i][j+1]);
        }
    }

    return mat[size1][size2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
