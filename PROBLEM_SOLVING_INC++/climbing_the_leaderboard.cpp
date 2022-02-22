/*An arcade game player wants to climb to the top of the leaderboard and track their ranking. The game uses Dense Ranking, so its leaderboard works like this:

The player with the highest score is ranked number 1 on the leaderboard.
Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.


Example
ranked = [100, 90, 90, 80]
player = [70, 80, 105]

The ranked players will have ranks 1, 2, 2, and 3, respectively. If the player's scores are 70, 80 and 105, their rankings after each game are 4th, 3rd and 1st. Return [4, 3, 1].


Function Description

Complete the climbingLeaderboard function in the editor below.

climbingLeaderboard has the following parameter(s):

int ranked[n]: the leaderboard scores
int player[m]: the player's scores

Returns

int[m]: the player's rank after each new score


Input Format

The first line contains an integer n, the number of players on the leaderboard.
The next line contains n space-separated integers ranked[i], the leaderboard scores in decreasing order.
The next line contains an integer, m, the number games the player plays.
The last line contains m space-separated integers player[j], the game scores.


Constraints
1 <= n, m <= 2 * 10^5
0 <= ranked[i], player[j] <= 10^9  for 0 <= i, j < n
The existing leaderboard, ranked, is in descending order.
The player's scores, player, are in ascending order.*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int score;
    set<int> s;
    for(int i=0;i<n;++i){ 
        cin>>score;
        s.insert(score);
    }
    set<int>::iterator it = s.begin();
    int rank = s.size()+1;
    int m;
    cin>>m;
    while(m--){
        cin>>score;
        while(*it<=score && it!=s.end()){
            ++it;--rank;
        }
        cout<<rank<<endl;
    }
    return 0;
}
