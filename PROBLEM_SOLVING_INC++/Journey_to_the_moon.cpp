/*The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID’s. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example

There are  astronauts numbered  through . Astronauts grouped by country are  and . There are  pairs to choose from:  and .

Function Description

Complete the journeyToMoon function in the editor below.

journeyToMoon has the following parameter(s):

int n: the number of astronauts
int astronaut[p][2]: each element  is a  element array that represents the ID’s of two astronauts from the same country
Returns
– int: the number of valid pairs

Input Format

The first line contains two integers  and , the number of astronauts and the number of pairs.
Each of the next  lines contains  space-separated integers denoting astronaut ID’s of two who share the same nationality.

Sample Input 0

5 3
0 1
2 3
0 4
Sample Output 0

6
Explanation 0

Persons numbered  belong to one country, and those numbered  belong to another. The UN has  ways of choosing a pair:

 

Sample Input 1

4 1
0 2
Sample Output 1

5*/
#include<bits/stdc++.h>
using namespace std;

int n, m;
int counter;
unordered_set<int> visited;
unordered_set<int> vertices;
vector<int> collectAnswers;
vector<int> adjacencyList[100000];


void dfs(int sv)
{
    visited.insert(sv);
    for (int i : adjacencyList[sv])
    {
        if (visited.find(i) != visited.end()) continue;
        visited.insert(i);
        dfs(i);
    }
    counter++;

}

void find_numbers()
{
    for (int i : vertices)
    {    counter = 0;
        if (visited.find(i) != visited.end()) continue;
        dfs(i);
        collectAnswers.push_back(counter);
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++) vertices.insert(i);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    
    find_numbers();
    long long answer = 0;
    long long sum = collectAnswers[0];
    for (int i = 1; i < collectAnswers.size(); i++)
    {
        answer += sum * collectAnswers[i];
        sum += collectAnswers[i];
    }
    cout << answer;

}
