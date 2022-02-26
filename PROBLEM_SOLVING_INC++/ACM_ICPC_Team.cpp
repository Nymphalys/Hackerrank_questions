/*There are a number of people who will be attending ACM-ICPC World Finals. Each of them may be well versed in a number of topics. Given a list of topics known by each attendee, presented as binary strings, determine the maximum number of topics a 2-person team can know. Each subject has a column in the binary string, and a ‘1’ means the subject is known while ‘0’ means it is not. Also determine the number of teams that know the maximum number of topics. Return an integer array with two elements. The first is the maximum number of topics known, and the second is the number of teams that know that number of topics.

Example

n=3

Topics = [‘10101’,’11110’,’00010’]

The attendee data is aligned for clarity below:

10101

11110

00010

 

These are all possible teams that can be formed:

Members Subjects

(1,2)   [1,2,3,4,5]

(1,3)   [1,3,4,5]

(2,3)   [1,2,3,4]

 

In this case, the first team will know all 5 subjects. They are the only team that can be created that knows that many subjects, so [5,1] is returned.

Function Description

Complete the acmTeam function in the editor below.

acmTeam has the following parameter(s):

string topic: a string of binary digits
Returns

int[2]: the maximum topics and the number of teams that know that many topics
Input Format

The first line contains two space-separated integers n and m, where n is the number of attendees and m is the number of topics.

Each of the next n lines contains a binary string of length m.

Constraints

2<=n<=500

Sample Input

4 5

10101

11100

11010

00101
 

Sample Output

5

2*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> acmTeam(vector<string> topic) {
    vector<int> finale ;
    
    for ( int i = 0 ; i < topic.size() ; i++ ) {
        for ( int j = i + 1 ; j < topic.size() ; j++ ) {
            int counter = 0 ;
            for ( int k = 0 ; k < topic[i].size() ; k++ ) {
                
                if ( topic[i][k] == '1' || topic[j][k] == '1' ) {
                    counter ++ ;
                }   
            }
            finale.push_back( counter ) ;    
            
        }
    }
    
   int highest = *max_element( finale.begin() , finale.end() ) ;
   int highestcount = count( finale.begin() , finale.end() , highest ) ;
   
   return { highest , highestcount } ;
   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

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
