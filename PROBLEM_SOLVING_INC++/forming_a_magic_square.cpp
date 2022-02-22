/*We define a magic square to be an n x n matrix of distinct positive integers from 1 to n2 where the sum of any row, column, or diagonal of length n is always equal to the same number: the magic constant.

You will be given a 3 x 3 matrix s of integers in the inclusive range [1, 9]. We can convert any digit a to any other digit b in the range [1, 9] at cost of |a – b|. Given s, convert it into a magic square at minimal cost. Print this cost on a new line.

Note: The resulting magic square must contain distinct integers in the inclusive range [1, 9].

Example

$s = [[5, 3, 4], [1, 5, 8], [6, 4, 2]]

The matrix looks like this:

5 3 4
1 5 8
6 4 2
We can convert it to the following magic square:

8 3 4
1 5 9
6 7 2
This took three replacements at a cost of |5 – 8| + |8 – 9| + |4 – 7| = 7.

Function Description

Complete the formingMagicSquare function in the editor below.

formingMagicSquare has the following parameter(s):

int s[3][3]: a 3 x 3 array of integers
Returns

int: the minimal total cost of converting the input square to a magic square
Input Format
Each of the 3 lines contains three space-separated integers of row s[i].

Constraints
s|i||j| belongs to [1, 9]
Sample Input 0

4 9 2
3 5 7
8 1 5
Sample Output 0

1
Explanation 0

If we change the bottom right value, s[2][2], from 5 to 6 at a cost of |6 – 5| = 1, s becomes a magic square at the minimum possible cost.

Sample Input 1

4 8 2
4 5 7
6 1 6
Sample Output 1

4
Explanation 1

Using 0-based indexing, if we make

s[0][1]->9 at a cost of |9 – 8| = 1
s[1][0]->3 at a cost of |3 – 4| = 1
s[2][0]->8 at a cost of |8 – 6| = 2,
then the total cost will be 1 + 1 + 2 = 4.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int formingMagicSquare(vector < vector<int> > s) {
    // Complete this function
    int pre[8][3][3]={
                      {{8, 1, 6},{3, 5, 7},{4, 9, 2}},
                      {{6, 1, 8},{7, 5, 3},{2, 9, 4}},
                      {{4, 9, 2},{3, 5, 7},{8, 1, 6}},
                      {{2, 9, 4},{7, 5, 3},{6, 1, 8}},
                      {{8, 3, 4},{1, 5, 9},{6, 7, 2}},
                      {{4, 3, 8},{9, 5, 1},{2, 7, 6}},
                      {{6, 7, 2},{1, 5, 9},{8, 3, 4}},
                      {{2, 7, 6},{9, 5, 1},{4, 3, 8}}
                        } ;
    vector<int> grpcost;
    for(int i=0;i<8;i++){
        int cost=0;
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
               if(s[j][k]!=pre[i][j][k]) {
                   cost+=abs(s[j][k]-pre[i][j][k]);
               } 
            }
        }
        grpcost.push_back(cost);
    }

    int mincost = *min_element(grpcost.begin(), grpcost.end());
    return mincost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
