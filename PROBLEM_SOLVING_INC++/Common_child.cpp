#include <bits/stdc++.h>

using namespace std;



int commonChild(string s1, string s2) {
    int size1 = s1.size();
    int size2 = s2.size();
    vector<vector<int>> mat(size1 + 1, vector<int>(size2 +1, 0));

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(s1[i] == s2[j]) mat[i+1][j+1] = 1 + mat[i][j];
            else mat[i+1][j+1] = max(mat[i+1][j], mat[i][j+1]);
        }
    }

    return mat[size1][size2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
