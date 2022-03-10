/*A weighted string is a string of lowercase English letters where each letter has a weight. Character weights are 1 to 26  from  a to z  as shown below:

The weight of a string is the sum of the weights of its characters. For example:

A uniform string consists of a single character repeated zero or more times. For example, ccc and a are uniform strings, but bcb and cd are not.

Function Description

Complete the weightedUniformStrings function in the editor below.

weightedUniformStrings has the following parameter(s):
- string s: a string
- int queries[n]: an array of integers

Returns
- string[n]: an array of strings that answer the queries

Input Format

The first line contains a string s, the original string.
The second line contains an integer n, the number of queries.
Each of the next s lines contains an integer queries[i], the weight of a uniform subtring of s that may or may not exist.

Constraints


1  <=  length of s,n  <=  10^5
1  <=   queries[i]  <=  10^7
s will only contain lowercase English letters, ascii[a-z].

*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


vector<string> weightedUniformStrings(string s, vector<int> queries) 
{
    int i,j,l=0,n,flag=0;
    n=s.length();
    vector<int> arr;
    vector<string> s1;
   
   j=1;
   for(i=0; i<s.length(); i++)
   {
        if(s[i]==s[i+1])
       {
           n=(s[i]-'a'+1)*j;
            arr.push_back(n);
            j++;

       }
       else if(s[i]!=s[i+1] && s[i]==s[i-1] && i>0)
       {
            n=(s[i]-'a'+1)*j;
            arr.push_back(n);
            j=1;
       }
        else if(s[i]!=s[i+1])
       {
           n=(s[i]-'a'+1);
           arr.push_back(n);
           j=1;
       }
   }

    n=arr.size();
    l=queries.size();

    for(i=0; i<l; i++)
    {
        flag=0;
        for(j=0; j<n; j++)
        {
            if(queries[i]==arr[j])
            {
                flag++;
                break;
            }
        }
        if(flag==0)
        { 
            s1.push_back("No");
        }
        else if(flag>0)
        {
             s1.push_back("Yes");
        }
    }

    return s1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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
