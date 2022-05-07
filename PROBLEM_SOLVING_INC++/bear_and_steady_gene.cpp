#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> map, check_map;
    vector<int> vec;

    //histogram
    for(char c: s){
        if(map.count(c)){
            map.find(c)->second++;
        }else{
            map.insert({c,1});
        }
    }
    int minimum = 0;
    for(auto& c: map){
        if(c.second > n/4){
            minimum += c.second - n/4;
            check_map.insert({c.first, c.second - n/4});            
        }     
    }

    if(check_map.empty()) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(check_map.count(s[i])){
            vec.push_back(i);
        }
    }
    
    int min = n;
    bool flag;

    for(int k = 0; k < minimum; k++)
        check_map.find(s[vec[k]])->second--;
    int j = minimum - 1;
    for(int i = 0; i < vec.size() - minimum; i++){
        int left = vec[i];
        while(1){
            flag = true;
            for(auto& c: check_map){ // check if all redundent is zero
                if(c.second > 0)
                    flag = false;
            }
            if(flag || (j + 1) == vec.size())
                break;
            j++;
            check_map.find(s[vec[j]])->second--;
        }
        int right = vec[j];
        if(min > right - left + 1 && flag)
             min = right - left + 1;
        if(min == minimum){
            cout << minimum << endl;
            return 0;
        }
        check_map.find(s[vec[i]])->second++;
    }
    cout << min << endl;
    return 0;
}
