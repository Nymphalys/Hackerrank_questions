#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int twice_median(vector<int> &expenditure,vector<int> &freq_count,int d){
    int sum=0;
    int n=freq_count.size();
    
    for(int i=0;i<n;++i){
        sum+=freq_count[i];

        if(2*sum>d) return (2*i);

        else if(2*sum==d){
            for(int j=i+1;i<n;++j){
                if(freq_count[j]) return (i+j);
            }
        }
    }
return -1;
    }

int activityNotifications(vector<int> expenditure, int d) {
    int count=0;
    vector<int> freq_count(201,0);
    int n=expenditure.size();

    for(int i=0;i<d;++i){
        freq_count[expenditure[i]]++;
    }
    
    for(int i=d;i<n;++i){
        int median=twice_median(expenditure,freq_count,d);
        
        if(expenditure[i]>=median) count++;
        freq_count[expenditure[i]]++;
        freq_count[expenditure[i-d]]--;
    }
return count;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
