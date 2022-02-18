/*Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: – 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
– 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example

s = ’12:01:00PM’
Return ’12:01:00′.
s = ’12:01:00AM’
Return ’00:01:00′.
Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

string s: a time in 12 hour format
Returns

string: the time in 24 hour format
Input Format
A single string s that represents a time in 12-hour clock format (i.e.: hh:mm:ssAM or hh:mm:ssPM).

Constraints
All input times are valid
Sample Input 0

07:05:45PM
Sample Output 0

19:05:45 */

#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {

    if (s[8]=='A') {
        if (s[0] == '1' && s[1] == '2') {
            return "00"+s.substr(2,6);
        }      
        return s.substr(0,8);
    } else {
        int clock = stoi(s.substr(0,2)) + 12;
        if (clock == 24) {
            return "12"+s.substr(2,6);
        }
        return to_string(clock) + s.substr(2,6);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
