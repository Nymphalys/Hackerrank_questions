/*Ema built a quantum computer! Help her test its capabilities by solving the problem below.

Given a grid of size n*m, each cell in the grid is either good or bad.

A valid plus is defined here as the crossing of two segments (horizontal and vertical) of equal lengths. These lengths must be odd, and the middle cell of its horizontal segment must cross the middle cell of its vertical segment.

In the diagram below, the blue pluses are valid and the orange ones are not valid. pluseses.png

Find the two largest valid pluses that can be drawn on good cells in the grid, and return an integer denoting the maximum product of their areas. In the above diagrams, our largest pluses have areas of 5 and 9. The product of their areas is 5*9=45.

Note: The two pluses cannot overlap, and the product of their areas should be maximal.

Function Description

Complete the twoPluses function in the editor below. It should return an integer that represents the area of the two largest pluses.

twoPluses has the following parameter(s):

grid: an array of strings where each string represents a row and each character of the string represents a column of that row

Input Format

The first line contains two space-separated integers,n and m.
Each of the next n lines contains a string of m characters where each character is either G (good) or B (bad). These strings represent the rows of the grid. If the yth character in the line is G, then (x,y) is a goo cell. Otherwise it’s a bad cell.

Output Format

Find 2 pluses that can be drawn on good cells of the grid, and return an integer denoting the maximum product of their areas.

Sample Input 0

5 6
GGGGGG
GBBBGB
GGGGGG
GGBBGB
GGGGGG
Sample Output 0

5
Sample Input 1

6 6
BGBBGB
GGGGGG
BGBBGB
GGGGGG
BGBBGB
BGBBGB
Sample Output 1

25*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int twoPluses(vector<string> gr) {
    static const vector<string> &grid = gr;
    static const int n = grid.size(), m = grid[0].size();
    class plus {
        int x, y, len, area;
    public:
        plus(int x, int y) : x(x), y(y), len(0), area(0) {}
        int getArea() { return area; }
        bool grow() {
            if(len == 0 and grid[x][y] == 'G') {
                len = 1;
                area = 1;
                return true;
            }
            if(x - len >= 0 and x + len < n 
            and y - len >= 0 and y + len < m 
            and grid[x - len][y] == 'G' and grid[x + len][y] == 'G' 
            and grid[x][y - len] == 'G' and grid[x][y + len] == 'G') {
                len += 1;
                area += 4;
                return true;
            }
            return false;
        }
        bool intersect(plus p) {
            int len = this->len - 1;
            if(x == p.x and x + len >= p.x - p.len and p.x + p.len >= x - len)
                return true;
            if(y == p.y and y + len >= p.y - p.len and p.y + p.len >= y - len)
                return true;
            if(p.x >= x - len and p.x <= x + len and p.y - p.len <= y and p.y + p.len >= y)
                return true;
            if(p.y >= y - len and p.y <= y + len and p.x - p.len <= x and p.x + p.len >= x)
                return true;
            return false;
        }
    };
    int maxAP = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            plus P(i, j);
            while(P.grow()) {
                cout << P.getArea() << " ";
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        plus p(i, j);
                        while(p.grow() and !P.intersect(p));
                        maxAP = max(maxAP, P.getArea() * p.getArea());
                    }
                }
            } cout << endl;
        }
    }
    return maxAP;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

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
