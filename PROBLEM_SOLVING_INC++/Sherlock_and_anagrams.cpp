/*Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

For example s = mom , the list of all anagrammatic pairs is [m,m], [mo, om] at positions [ [1], [2], [0,1], [1,2] ] respectively .

Function Description

Complete the function sherlockAndAnagrams in the editor below. It must return an integer that represents the number of anagrammatic pairs of substrings in s.

sherlockAndAnagrams has the following parameter(s)
     s: a string .

Input Format

The first line contains an integer q , the number of queries .
Each of the next  q lines contains a string s to analyze.

Constraints
  
   1 <= q <= 10
   2 <= | s| <= 100


Output Format

For each query, return the number of unordered anagrammatic pairs.*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int sherlockAndAnagrams(string s) {
    int ans = 0;
    unordered_map<string, int> m;
    unordered_map<string, int>::iterator it;
    
    int pos = 0;
    int len = 1;
    for(pos = 0; pos < s.length(); pos++)
        for(len = 1; pos + len - 1 < s.length(); len++){
            string s1 = s.substr(pos,len);
            sort(s1.begin(), s1.end());
            it = m.find(s1);
            if(it != m.end())
                (*it).second++;
            else
                m.insert(make_pair(s1, 1));
        }
    for(it = m.begin(); it != m.end(); it++){
        int n = (*it).second;
        ans += (n * (n-1))/2;
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

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
