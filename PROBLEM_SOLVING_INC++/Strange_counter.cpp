/*There is a strange counter. At the first second, it displays the number 3. Each second, the number displayed by decrements by 1 until it reaches 1. In next second, the timer resets to 2*the initial number for the prior cycle and continues counting down. The diagram below shows the counter values for each time t in the first three cycles:

Find and print the value displayed by the counter at time t.

Function Description

Complete the strangeCounter function in the editor below.

strangeCounter has the following parameter(s):

int t: an integer

Returns

int: the value displayed at time t

Input Format

A single integer, the value of t.

Sample Input

4
Sample Output

6
Explanation

Time t=4 marks the beginning of the second cycle. It is double the number displayed at the beginning of the first cycle:2*3=6. This is shown in the diagram in the problem statement.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



long strangeCounter(long t) {
    long v=4;

    while(v<=t)
    {
        v=v*2+2;
    }
    return v-t;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    long t = stol(ltrim(rtrim(t_temp)));

    long result = strangeCounter(t);

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
