/*The city of Gridland is represented as an n x m matrix where the rows are numbered from 1 to n and the columns are numbered from 1 to m.

Gridland has a network of train tracks that always run in straight horizontal lines along a row. In other words, the start and end points of a train track are  and , where  represents the row number,  represents the starting column, and  represents the ending column of the train track.

The mayor of Gridland is surveying the city to determine the number of locations where lampposts can be placed. A lamppost can be placed in any cell that is not occupied by a train track.

Given a map of Gridland and its  train tracks, find and print the number of cells where the mayor can place lampposts.

Note: A train track may overlap other train tracks within the same row.


In this case, there are five open cells (red) where lampposts can be placed.

Function Description

Complete the gridlandMetro function in the editor below.

gridlandMetro has the following parameter(s):

int n:: the number of rows in Gridland
int m:: the number of columns in Gridland
int k:: the number of tracks
track[k][3]: each element contains  integers that represent , all 1-indexed
Returns

int: the number of cells where lampposts can be installed
Input Format

The first line contains three space-separated integers  and , the number of rows, columns and tracks to be mapped.

Each of the next  lines contains three space-separated integers,  and , the row number and the track column start and end.

*/
#include <bits/stdc++.h>

using namespace std;


unsigned long long int gridlandMetro(long n, long m, long k, vector<vector<long>> track) {
unsigned long long int res = 0;
unordered_map<int,vector<pair<int,int> >>mp;
for(long unsigned int i = 0; i < track.size(); i++){
    mp[track[i][0]].push_back({track[i][1],track[i][2]}); 
}
unsigned long long int fr  = mp.size();
unsigned long long int mul = n-fr;
res += mul*m;vector<pair<int,int> >vec;stack<pair<int,int> >st; 
for(auto it = mp.begin(); it != mp.end();++it){
    vec = it->second;
    for(long unsigned int i = 0; i < vec.size(); i++){
        if(st.empty()){
            st.push(vec[i]);
        }
        else{
            if(vec[i].first <= st.top().second){
                auto p = st.top(); st.pop();
                p.second = max(p.second,vec[i].second);
                st.push(p);
            }
            else{
                st.push(vec[i]);
            }
        }
    
    }
    unsigned long long int sum = 0;
    while(!st.empty()){
       
        sum += (st.top().second-st.top().first)+1;
        st.pop();
    } 
    res += m-sum;
}

return res;
}

int main()
{
   long n,m,k;
   cin>>n>>m>>k;
   vector<vector<long> >vec;
   for(int i = 0; i < k; i++){
       vector<long>v(3);
       for(int i = 0; i < 3; i++){
           cin>>v[i];
       }
    vec.push_back(v);
   }
  unsigned long long int res = gridlandMetro(n,m,k,vec);
  cout<<res;
}
