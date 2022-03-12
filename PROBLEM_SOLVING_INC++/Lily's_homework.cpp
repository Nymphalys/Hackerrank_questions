/*Whenever George asks Lily to hang out, she's busy doing homework. George wants to help her finish it faster, but he's in over his head! Can you help George understand Lily's homework so she can hang out with him?

Consider an array of  distinct integers, . George can swap any two elements of the array any number of times. An array is beautiful if the sum of  among  is minimal.

Given the array , determine and return the minimum number of swaps that should be performed in order to make the array beautiful.

Function Description

Complete the lilysHomework function in the editor below.

lilysHomework has the following parameter(s):

int arr[n]: an integer array
Returns

int: the minimum number of swaps required

Input Format

The first line contains a single integer, n, the number of elements in arr. The second line contains  n space-separated integers, arr[i].
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int lilysHomework(vector<int> arr) {
    vector<int> sortedINC = arr;
    vector<int> sortedDESC = arr;
    vector<int> arr2 = arr;
    sort(begin(sortedINC), end(sortedINC)); 
    sort(begin(sortedDESC), end(sortedDESC), greater<int>()); 
    unordered_map<int, int> valIdxMapINC, valIdxMapDESC;
    for (int i = 0; i < sortedINC.size(); i++) {
        valIdxMapINC[sortedINC[i]] = i;
    }
   
    for (int i = 0; i < sortedDESC.size(); i++) {
        valIdxMapDESC[sortedDESC[i]] = i;
    }
    int szI = 0, szD = 0, size = arr.size() - 1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != sortedINC[i]) {
            swap(arr[i], arr[valIdxMapINC[arr[i]]]);
            szI++;
            i--;
        }
    }
    
    for (int i = 0; i < arr2.size(); i++) {
        if (arr2[i] != sortedDESC[i]) {
            swap(arr2[i], arr2[valIdxMapDESC[arr2[i]]]);
            szD++;
            i--;
        }
    }
    return min(szI, szD);
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

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
