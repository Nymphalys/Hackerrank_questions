/*Given a sequence of n integers, p(1), p(2),......, P(n)  where each element is distinct and satisfies 1 <= p(x) <= n. For each x where 1<= x <= n, that is x increments from 1 to n, find any integer y such that p(p(y)) = x  and keep a history of the values of u in a return array.


Example
p = [5, 2, 1, 3, 4]

Each value of x between 1 and 5, the length of the sequence, is analyzed as follows:

1.  x = 1 = p[3], p[4] = 3, so p[p[4]] = 1
2.  x = 2 = p[2], p[2] = 2, so p[p[2]] = 2
3.  x = 3 = p[4], p[5] = 4, so p[p[5]] = 3
4.  x = 4 = p[5], p[1] = 5, so p[p[1]] = 4
5.  x = 5 = p[1], p[3] = 1, so p[p[3]] = 5

The values for y are [4, 2, 5, 1, 3].


Function Description

Complete the permutationEquation function in the editor below.
permutationEquation has the following parameter(s):
int p[n]: an array of integers

Returns

int[n]: the values of y for all x in the arithmetic sequence 1 to n


Input Format

The first line contains an integer n, the number of elements in the sequence.
The second line contains n space-separated integers p[i] where 1 <= i <= n.


Constraints
1 <= n <= 50
1 <= p[i[ <= 50, where 1 <= i <= n.
Each element in the sequence is distinct.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> permutationEquation(vector<int> p) {
int size = p.size();
vector<int> y(size, 0);
for(int i = 0; i < size; i++)
    y[p[p[i] - 1] - 1] = i + 1;

return y;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split(rtrim(p_temp_temp));

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    vector<int> result = permutationEquation(p);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
