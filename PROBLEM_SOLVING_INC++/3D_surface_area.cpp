/*Madison, is a little girl who is fond of toys. Her friend Mason works in a toy manufacturing factory . Mason has a 2D board A of size with H*W with H rows and W columns. The board is divided into cells of size 1*1 with each cell indicated by it’s coordinate (i,j). The cell (i,j) has an integer Aij written on it. To create the toy Mason stacks Aij number of cubes of size 1*1*1 on the cell (i,j).

Given the description of the board showing the values of Aij and that the price of the toy is equal to the 3d surface area find the price of the toy.

Input Format

The first line contains two space-separated integers H and W the height and the width of the board respectively.

The next H lines contains W space separated integers. The jth integer ith in line denotes .

Output Format

Print the required answer, i.e the price of the toy, in one line.

Sample Input 0

1 1
1
Sample Output 0

6
Explanation 0

image The surface area of cube is 6.

Sample Input 1

3 3
1 3 4
2 2 3
1 2 4
Sample Output 1

60
Explanation 1

The sample input corresponds to the figure described in problem statement.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int surfaceArea(vector<vector<int>> A) {
    int sum=0;
    for (int i=0;i<A.size();i++)
        for (int j=0;j<A[0].size();j++)
        {
            sum+=A[i][j]*4+2;
            if (j+1<A[0].size())    sum-=2*min(A[i][j], A[i][j+1]);
            if (i+1<A.size())    sum-=2*min(A[i][j], A[i+1][j]);
        }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++) {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

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
