/*n a previous challenge you implemented the Insertion Sort algorithm. It is a simple sorting algorithm that works well with small or mostly sorted data. However, it takes a long time to sort large unsorted data. To see why, we will analyze its running time.

Running Time of Algorithms

The running time of an algorithm for a specific input depends on the number of operations executed. The greater the number of operations, the longer the running time of an algorithm. We usually want to know how many operations an algorithm will execute in proportion to the size of its input, which we will call .

What is the ratio of the running time of Insertion Sort to the size of the input? To answer this question, we need to examine the algorithm.

Analysis of Insertion Sort

For each element  in an array of  numbers, Insertion Sort compares the number to those to its left until it reaches a lower value element or the start. At that point it shifts everything to the right up one and inserts  into the array.

How long does all that shifting take?

In the best case, where the array was already sorted, no element will need to be moved, so the algorithm will just run through the array once and return the sorted array. The running time would be directly proportional to the size of the input, so we can say it will take  time.

However, we usually focus on the worst-case running time (computer scientists are pretty pessimistic). The worst case for Insertion Sort occurs when the array is in reverse order. To insert each number, the algorithm will have to shift over that number to the beginning of the array. Sorting the entire array of  numbers will therefore take  operations, which is  (almost ). Computer scientists just round that up (pick the dominant term) to  and say that Insertion Sort is an " time" algorithm.


Challenge
Can you modify your previous Insertion Sort implementation to keep track of the number of shifts it makes while sorting? The only thing you should print is the number of shifts made by the algorithm to completely sort the array. A shift occurs when an element's position changes in the array. Do not shift an element if it is not necessary.

Function Description

Complete the runningTime function in the editor below.

runningTime has the following parameter(s):

int arr[n]: an array of integers


Returns

int: the number of shifts it will take to sort the array

Input Format

The first line contains the integer n, the number of elements to be sorted.
The next line contains n integers of arr[ arr[0] . . .arr[ n - 1 ] ] .*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int runningTime(vector<int> arr) {
    vector<int> buff = arr;
    sort(buff.begin(), buff.end());
    int c = 0, ans = 0;
    while(buff != arr){
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] < arr[i-1]){
                iter_swap(arr.begin() + (i-1), arr.begin() + i);
                ans++;      
            }
        }
    }
    return ans;
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

    int result = runningTime(arr);

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
