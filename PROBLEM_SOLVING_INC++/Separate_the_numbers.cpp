/*A numeric string,s , is beautiful if it can be split into a sequence of two or more positive integers,a[1],a[2],…,a[n], , satisfying the following conditions:

a[i]-a[i-1]=1 for any 1<i<=n (i.e., each element in the sequence is 1 more than the previous element).
No a[i] contains a leading zero. For example, we can split s=10203 into the sequence {1,02,03}, but it is not beautiful because 02 and  03 have leading zeroes.
The contents of the sequence cannot be rearranged. For example, we can split s=312 into the sequence {3,1,2}, but it is not beautiful because it breaks our first constraint (i.e.,1-3!=1 ).
The diagram below depicts some beautiful strings:

You must perform q queries where each query consists of some integer string s. For each query, print whether or not the string is beautiful on a new line. If it’s beautiful, print YES x, where x is the first number of the increasing sequence. If there are multiple such values of x, choose the smallest. Otherwise, print NO.

Function Description

Complete the separateNumbers function in the editor below. It should print a string as described above.

separateNumbers has the following parameter:

s: an integer value represented as a string
Input Format

The first line contains an integer q, the number of strings to evaluate.

Each of the next q lines contains an integer string s to query.

Constraints

1<=q<=10
1<=|s|<=32
S[i] belongs to [0 – 9]
Output Format

For each query, print its answer on a new line (i.e., either YES x where  is the smallest first number of the increasing sequence, or NO).

Sample Input 0

7

1234

91011

99100

101103

010203

13

1
 

Sample Output 0

YES 1

YES 9

YES 99

NO

NO

NO

NO
 

Explanation 0

The first three numbers are beautiful (see the diagram above). The remaining numbers are not beautiful:

For ,s=101103 all possible splits violate the first and/or second conditions.
For ,s=010203 it starts with a zero so all possible splits violate the second condition.
For ,s=13 the only possible split is {1,3}, which violates the first condition.
For ,s=1 there are no possible splits because s only has one digit.
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



void separateNumbers(string s) {
    vector<string>result;
    string str1{}, str2{};

    if(s.length() <= 1) { cout << "NO" << endl; return; }
    else
    {
        bool flag{false};
        unsigned int i{0}, j{1}, step{1};
        string::size_type pos{j};
        while(j<s.length())
        {
            str1 = s.substr(i,step);
            unsigned long long tempint = stoull(str1);
            str2 = to_string(tempint+1);
            pos = j;
            pos = s.find(str2,pos);
            if(pos != string::npos && pos == j)
            {
                result.push_back(str1);
                step = str2.length();
                i = pos;
                j = pos+step;
                flag = true;
            }
            else
            {
                ++step;
                j = step;
                flag = false;
                result.clear();
                i = 0;
                if(j > s.length()/2) { break; }
            }
        }
        if(flag == true && result.size() > 0) { cout << "YES " << result[0] << endl; }
        else { cout << "NO" << endl; }
    }
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
