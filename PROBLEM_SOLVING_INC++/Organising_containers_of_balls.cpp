/*Taum is planning to celebrate the birthday of his friend, Diksha. There are two types of gifts that Diksha wants from Taum: one is black and the other is white. To make her happy, Taum has to buy b black gifts and  white gifts.

The cost of each black gift is bc units.
The cost of every white gift is wc units.
The cost to convert a black gift into white gift or vice versa is  units.
Determine the minimum cost of Diksha’s gifts.

Example

b=3

w=5

bc=3

wc=4

z=1

He can buy a black gift for 3 and convert it to a white gift for 1, making the total cost of each white gift 4. That matches the cost of a white gift, so he can do that or just buy black gifts and white gifts. Either way, the overall cost is 3*3+5*4=29.

Function Description

Complete the function taumBday in the editor below. It should return the minimal cost of obtaining the desired gifts.

taumBday has the following parameter(s):

int b: the number of black gifts
int w: the number of white gifts
int bc: the cost of a black gift
int wc: the cost of a white gift
int z: the cost to convert one color gift to the other color
Returns

int: the minimum cost to purchase the gifts
Input Format

The first line will contain an integer t, the number of test cases.

The next t pairs of lines are as follows:

– The first line contains the values of integers b and w.
– The next line contains the values of integers bc,wc , and z.

Constraints

1<=t<=10

0<=b,w,b,wc,z<=10^9

Output Format

 lines, each containing an integer: the minimum amount of units Taum needs to spend on gifts.

Sample Input

STDIN   Function

-----   --------

5       t = 5

10 10   b = 10, w = 10

1 1 1   bc = 1, wc = 1, z = 1

5 9     b = 5, w = 5

2 3 4   bc = 2, wc = 3, z = 4

3 6     b = 3, w = 6

9 1 1   bc = 9, wc = 1, z = 1

7 7     b = 7, w = 7

4 2 1   bc = 4, wc = 2, z = 1

3 3     b = 3, w = 3

1 9 2   bc = 1, wc = 9, z = 2
 

Sample Output

20

37

12

35

12*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    
    vector<long long int> row(n);
    vector<long long int> col(n);
 
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            row[i] += container[i][j];
            col[i] += container[j][i];
        }
    }
    
    sort(row.begin(),row.end());
    sort(col.begin(),col.end());
    
    if(row == col)
        return "Possible";
    else return "Impossible";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> container(n);

        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            string container_row_temp_temp;
            getline(cin, container_row_temp_temp);

            vector<string> container_row_temp = split(rtrim(container_row_temp_temp));

            for (int j = 0; j < n; j++) {
                int container_row_item = stoi(container_row_temp[j]);

                container[i][j] = container_row_item;
            }
        }

        string result = organizingContainers(container);

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
