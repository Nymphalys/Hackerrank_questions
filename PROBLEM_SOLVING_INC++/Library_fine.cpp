/*Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:

1. If the book is returned on or before the expected return date, no fine will be charged (i.e.: fine = 0).
2. If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, 
fine = 15 Hackos * (the number of days late).
3. If the book is returned after the expected return month but still within the same calendar year as the expected return date, the 
fine = 500 Hackos * (the number of months late).
4. If the book is returned after the calendar year in which it was expected, there is a fixed fine of 10000 Hackos.

Charges are based only on the least precise measure of lateness. For example, whether a book is due January 1, 2017 or December 31, 2017, if it is returned January 1, 2018, that is a year late and the fine would be 10000 Hackos.


Example
d1, m1, y1 = 14, 7, 2018
d2, m2, y2 = 5, 7, 2018

The first values are the return date and the second are the due date. The years are the same and the months are the same. The book is 14 - 5 = 9 days late. Return 9 * 5 = 135.


Function Description

Complete the libraryFine function in the editor below.

libraryFine has the following parameter(s):

d1, m1, y1: returned date day, month and year, each an integer
d2, m2, y2: due date day, month and year, each an integer

Returns
int: the amount of the fine or 0 if there is none


Input Format

The first line contains 3 space-separated integers, d1, m1, y1, denoting the respective day, month  and year on which the book was returned.
The second line contains 3 space-separated integers, d2, m2, y2, denoting the respective day, month  and year on which the book was due to be returned.

Constraints
1 <= d1, d2 <= 31
1 <= m1, m2 <=12
1 <= y1, y2 <= 3000
It is guaranteed that the dates will be valid Gregorian calender dates.*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    if(y1 < y2){
        return 0;
    }
    else if(y1 > y2){
        return abs(y2 - y1)*10000;
    }
    
    if(m1 > m2 && y2 == y1){
        return abs(m1 - m2)*500;
    }
    else if(m1 < m2 && y2 == y1){
        return 0;
    }
    if(d1 < d2 && m2 == m1 && y2 == y1){
        return 0;
    }
    else if(d1 > d2 && m2 == m1 && y2 == y1){
        return abs(d1 - d2)*15;
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int d1 = stoi(first_multiple_input[0]);

    int m1 = stoi(first_multiple_input[1]);

    int y1 = stoi(first_multiple_input[2]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int d2 = stoi(second_multiple_input[0]);

    int m2 = stoi(second_multiple_input[1]);

    int y2 = stoi(second_multiple_input[2]);

    int result = libraryFine(d1, m1, y1, d2, m2, y2);

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
