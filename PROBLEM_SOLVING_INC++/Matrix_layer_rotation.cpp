/*You are given a 2D matrix of dimension m*n and a positive integer r. You have to rotate the matrix r times and print the resultant matrix. Rotation should be in anti-clockwise direction.

Rotation of a 4×5 matrix is represented by the following figure. Note that in one rotation, you have to shift elements by one step only.

matrix-rotation

It is guaranteed that the minimum of m and n will be even.

As an example rotate the Start matrix by 2:

Start         First           Second
 1 2 3 4        2  3  4  5      3  4  5  6
12 1 2 5  ->   1  2  3  6 ->   2  3  4  7
11 4 3 6      12  1  4  7       1  2  1  8
10 9 8 7      11 10  9  8     12 11 10  9
Function Description

Complete the matrixRotation function in the editor below. It should print the resultant 2D integer array and return nothing.

matrixRotation has the following parameter(s):

matrix: a 2D array of integers
r: an integer that represents the rotation factor

Input Format

The first line contains three space separated integers, m, n, and r, the number of rows and columns in matrix, and the required rotation.
The next lines contain space-separated integers representing the elements of a row of .

Output Format

Print each row of the rotated matrix as space-separated integers on separate lines.

Sample Input

Sample Input #01

4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output #01

3 4 8 12
2 11 10 16
1 7 6 15
5 9 13 14
Explanation #01

The matrix is rotated through two rotations.

 1  2  3  4      2  3  4  8      3  4  8 12
 5  6  7  8      1  7 11 12      2 11 10 16
 9 10 11 12  ->  5  6 10 16  ->  1  7  6 15
13 14 15 16      9 13 14 15      5  9 13 14
Sample Input #02

5 4 7
1 2 3 4
7 8 9 10
13 14 15 16
19 20 21 22
25 26 27 28
Sample Output #02

28 27 26 25
22 9 15 19
16 8 21 13
10 14 20 7
4 3 2 1
Explanation 02

The various states through 7 rotations:

1  2  3  4      2  3  4 10    3  4 10 16    4 10 16 22
7  8  9 10      1  9 15 16    2 15 21 22    3 21 20 28
13 14 15 16 ->  7  8 21 22 -> 1  9 20 28 -> 2 15 14 27 ->
19 20 21 22    13 14 20 28    7  8 14 27    1  9  8 26
25 26 27 28    19 25 26 27    13 19 25 26   7 13 19 25

10 16 22 28    16 22 28 27    22 28 27 26    28 27 26 25
 4 20 14 27    10 14  8 26    16  8  9 25    22  9 15 19
 3 21  8 26 ->  4 20  9 25 -> 10 14 15 19 -> 16  8 21 13
 2 15  9 25     3 21 15 19     4 20 21 13    10 14 20  7
 1  7 13 19     2  1  7 13     3  2  1  7     4  3  2  1
Sample Input #03

2 2 3
1 1
1 1
Sample Output #03

1 1
1 1
Explanation #03

All of the elements are the same, so any rotation will repeat the same matrix.

 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void matrixRotation(vector<vector<int>> matrix, int c) {
    int h = matrix.size();
    int w = matrix[0].size();

   
    for(int r = 0; r < min(h,w) / 2; r++){    
         
        int ring_h = h - r - r;
        int ring_w = w - r - r;

        int ring_len = 0;

        if(ring_h > 0)
            ring_len += (ring_h * 2);
        
        if(ring_w > 0)
            ring_len += (ring_w * 2);

        if(ring_h > 0 && ring_w > 0)
            ring_len -= 4;

        int cycles = c % ring_len;
                        
        while(cycles > 0){
            int next = 0;
            int prec = matrix[r + 1][w - r - 1];
            
            for(int x = w - r - 1; x >= r; x--){
                next = matrix[r][x];
                matrix[r][x] = prec;
                prec = next;
            }
           
            for(int y = r + 1; y < h - r; y++){
                next = matrix[y][r];
                matrix[y][r] = prec;
                prec = next;
            }
           
            for(int x = r + 1; x < w - r; x++){
                next = matrix[h - r - 1][x];
                matrix[h - r - 1][x] = prec;
                prec = next;
            }
            
            for(int y = h - r - 2; y >= r; y--){
                next = matrix[y][w - r - 1];
                matrix[y][w - r - 1] = prec;
                prec = next;
            }
            cycles--;
        }

    }

       
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            cout << matrix[y][x] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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
