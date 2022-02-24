/*A child is playing a cloud hopping game. In this game, there are sequentially numbered clouds that can be thunderheads or cumulus clouds. The character must jump from cloud to cloud until it reaches the start again.

There is an array of clouds, c and an energy level e = 100. The character starts from c[0] and uses 1 unit of energy to make a jump of size k to cloud c[(i+k)%n]. If it lands on a thundercloud, c[i] = 1, its energy (e) decreases by 2 additional units. The game ends when the character lands back on cloud 0.

Given the values of n, k, and the configuration of the clouds as an array c, determine the final value of e after the game ends.

Example. 
c = [0, 0, 1, 0]
k = 2

The indices of the path are 0-->2-->0. The energy level reduces by 1 for each jump to 98. The character landed on one thunderhead at an additional cost of 2 energy units. The final energy level is 96.

Note: Recall that % refers to the modulo operation. In this case, it serves to make the route circular. If the character is at c[n-1] and jumps 1, it will arrive at c[0.


Function Description

Complete the jumpingOnClouds function in the editor below.

jumpingOnClouds has the following parameter(s):

int c[n]: the cloud types along the path
int k: the length of one jump

Returns

int: the energy level remaining.


Input Format

The first line contains two space-separated integers, n and k, the number of clouds and the jump distance.
The second line contains n space-separated integers c[i] where 0 <= i < n. Each cloud is described as follows:
1.  If c[i] = 0, then cloud i is a cumulus cloud.
2.  If c[i] =1, then cloud i is a thunderhead.


Constraints
2 <= n <= 25
1 <= k <= n
n%k = 0
c[i] belongs to {0, 1}*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int jumpingOnClouds(vector<int> c, int k) {
    int n = c.size();
    int l = k % n;
    int e = 100;
    
    e--;
    if(c[0] == 1) {
        e = e-2;
    }
    while(l) {
        e--;
        if(c[l] == 1) {
            e = e-2;
        }
        l = (l + k) % n;
    }
    
    return e;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
