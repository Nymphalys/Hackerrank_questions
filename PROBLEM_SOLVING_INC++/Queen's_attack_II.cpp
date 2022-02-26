/*You will be given a square chess board with one queen and a number of obstacles placed on it. Determine how many squares the queen can attack.

A queen is standing on an  chessboard. The chess board’s rows are numbered from  to , going from bottom to top. Its columns are numbered from  to , going from left to right. Each square is referenced by a tuple, , describing the row, , and column, , where the square is located.

The queen is standing at position . In a single move, she can attack any square in any of the eight directions (left, right, up, down, and the four diagonals). In the diagram below, the green circles denote all the cells the queen can attack from :

There are obstacles on the chessboard, each preventing the queen from attacking any square beyond it on that path. For example, an obstacle at location  in the diagram above prevents the queen from attacking cells , , and :

Given the queen’s position and the locations of all the obstacles, find and print the number of squares the queen can attack from her position at . In the board above, there are  such squares.

Function Description

Complete the queensAttack function in the editor below. It should return an integer that describes the number of squares the queen can attack.

queensAttack has the following parameters:

– n: an integer, the number of rows and columns in the board

– k: an integer, the number of obstacles on the board

– r_q: integer, the row number of the queen’s position

– c_q: integer, the column number of the queen’s position

– obstacles: a two dimensional array of integers where each element is an array of  integers, the row and column of an obstacle

Input Format

The first line contains two space-separated integers  and , the length of the board’s sides and the number of obstacles.

The next line contains two space-separated integers  and , the queen’s row and column position.

Each of the next  lines contains two space-separated integers  and , the row and column position of .

Output Format

Print the number of squares that the queen can attack from position .

Sample Input 0

4 0

4 4
 

Sample Output 0

9
 

Explanation 0

The queen is standing at position  on a  chessboard with no obstacles:

Sample Input 1

5 3

4 3

5 5

4 2

2 3
 

Sample Output 1

10
 

Explanation 1

The queen is standing at position  on a  chessboard with  obstacles:

The number of squares she can attack from that position is .

Sample Input 2

1 0

1 1
 

Sample Output 2

0
 

Explanation 2

Since there is only one square, and the queen is on it, the queen can move 0 squares.*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    pair<int,int> lu = {n+r_q + c_q - n,0};
    if(lu.first > n+1){
        lu.second = abs(lu.first - n) - 1;
        lu.first = n+1;
    }

    pair<int,int> ld;
    pair<int,int> ru;
    pair<int,int> rd = {lu.second,lu.first};
    if(r_q < c_q){
        ru = {abs(abs(r_q - c_q) - n) + 1,n+1};
        ld = {0,abs(r_q - c_q)};
    }
    else if(r_q > c_q){
        ru = {n+1,abs(abs(r_q - c_q) - n) + 1};
        ld = {abs(r_q - c_q),0};
    }
    else{
        ru = {n+1,n+1};
        ld = {0,0};
    }

    int ql = 0;
    int qr = n+1;
    int qu = n+1;
    int qd = 0;
    int ans = 0;
    for(int i = 0; i < obstacles.size(); i++){
        if(obstacles[i][0] < r_q && obstacles[i][1] < c_q && ((r_q - c_q) == (obstacles[i][0] - obstacles[i][1]))){
            ld = max(ld, {obstacles[i][0], obstacles[i][1]});
        }
        else if(obstacles[i][0] > r_q && obstacles[i][1] > c_q && ((r_q - c_q) == (obstacles[i][0] - obstacles[i][1]))){
            ru = min(ru, {obstacles[i][0], obstacles[i][1]});
        }
        else if(((obstacles[i][0] + obstacles[i][1]) == (r_q + c_q)) && r_q > obstacles[i][0]){
            if(rd.first < obstacles[i][0]){
                rd = {obstacles[i][0],obstacles[i][1]};
            }
        }
        else if(((obstacles[i][0] + obstacles[i][1]) == (r_q + c_q)) && r_q < obstacles[i][0]){
            if(lu.first > obstacles[i][0]){
                lu = {obstacles[i][0],obstacles[i][1]};
            }
        }
        else if(r_q == obstacles[i][0]){
            if(c_q < obstacles[i][1]){
                qr = min(qr, obstacles[i][1]);
            }
            else{
                ql = max(ql, obstacles[i][1]);
            }
        }
        else if(c_q == obstacles[i][1]){
            if(r_q < obstacles[i][0]){
                qu = min(qu, obstacles[i][0]);
            }
            else{
                qd = max(qd, obstacles[i][0]);
            }
        }

    }
    ans+=abs(lu.first - r_q) - 1;
    ans+=abs(ru.first - r_q) - 1;
    ans+=abs(rd.first - r_q) - 1;
    ans+=abs(ld.first - r_q) - 1;
    ans+=abs(ql - c_q) - 1;
    ans+=abs(qr - c_q) - 1;
    ans+=abs(qu - r_q) - 1;
    ans+=abs(qd - r_q) - 1;
    return ans;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
