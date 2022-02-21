/*A teacher asks the class to open their books to a page number. A student can either start turning pages from the front of the book or from the back of the book. They always turn pages one at a time. When they open the book, page 1 is always on the right side:

When they flip page 1, they see pages 2 and 3. Each page except the last page will always be printed on both sides. The last page may only be printed on the front, given the length of the book. If the book is n pages long, and a student wants to turn to page p, what is the minimum number of pages to turn? They can start at the beginning or the end of the book.

Given n and p, find and print the minimum number of pages that must be turned in order to arrive at page p.


Example
n = 5
p = 3

if the student wants to get to page 3, they open the book to page 1, flip 1 page and they are on the correct page. If they open the book to the last page, page 5, they turn 1 page and are at the correct page. Return 1.


Function Description

Complete the pageCount function in the editor below.

pageCount has the following parameter(s):

int n: the number of pages in the book
int p: the page number to turn to

Returns

int: the minimum number of pages to turn


Input Format

The first line contains an integer n, the number of pages in the book.
The second line contains an integer, p, the page to turn to.


Constraints
1 <= n <= 10^5
1 <= p <= n */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int pageCount(int n, int p) {
    unordered_map<int,vector<int>> m;
    vector<int> vc;
    vc.push_back(-1);
    vc.push_back(1);
    m[0] = vc;
    int k=1;
    for(int i=2;i<=n;){
        vector<int> v;
        v.push_back(i);
        if(i+1<=n){
            v.push_back(i+1);
        }
        m[k] = v;
        k++;
        i+=2;
    }
     unordered_map<int,vector<int>>::iterator it;

    int pos = 0;
    for(it = m.begin();it!=m.end();it++){
        if(count(it->second.begin(),it->second.end(),p)){
            pos = it->first;
            break;
        }
    }
    int res_f = abs(pos-0);
    int res_b = (m.size()-pos-1);
    return min(res_f,res_b);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

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
