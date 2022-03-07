/*There is a collection of rocks where each rock has various minerals embeded in it. Each type of mineral is designated by a lowercase letter in the range ascii[a-z]. There may be multiple occurrences of a mineral in a rock. A mineral is called a gemstone if it occurs at least once in each of the rocks in the collection.

Given a list of minerals embedded in each of the rocks, display the number of types of gemstones in the collection.

Example

arr=[‘abc’,’abc’,’bc’]

The minerals b and c appear in each rock, so there are  gemstones.

Function Description

Complete the gemstones function in the editor below.

gemstones has the following parameter(s):

string arr[n]: an array of strings
Returns

int: the number of gemstones found
Input Format

The first line consists of an integer n, the size of arr.

Each of the next n lines contains a string arr[i] where each letter represents an occurence of a mineral in the current rock.

Constraints

1<=n<=100

 1<=| arr[i] |<=100 

Each composition  consists of only lower-case Latin letters (‘a’-‘z’).

Sample Input

STDIN       Function

-----       --------

3           arr[] size n = 3

abcdde      arr = ['abcdde', 'baccd', 'eeabg']

baccd

eeabg
 

Sample Output

2
 

Explanation

Only a and b occur in every rock.*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int gemstones(vector<string> arr) {
    int alpha[26][2]={{0,0}}, count=0;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(alpha[arr[i][j]-'a'][1]!=1){  
                alpha[arr[i][j]-'a'][0]++;
                alpha[arr[i][j]-'a'][1]=1;
            }
        }
        for(int k=0;k<26;k++){
            alpha[k][1]=0;
        }
    }
    for(int i=0;i<26;i++){
        if(alpha[i][0]==arr.size()){
            count++;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

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
