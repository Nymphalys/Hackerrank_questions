/*Many of the challenges on HackerRank are difficult and assume that you already know the relevant algorithms. These tutorial challenges are different. They break down algorithmic concepts into smaller challenges so that you can learn the algorithm by solving them. They are intended for those who already know some programming, however. You could be a student majoring in computer science, a self-taught programmer, or an experienced developer who wants an active algorithms review. Here's a great place to learn by doing!

The first series of challenges covers sorting. They are listed below:

Tutorial Challenges - Sorting

Insertion Sort challenges

Insertion Sort 1 - Inserting
Insertion Sort 2 - Sorting
Correctness and loop invariant
Running Time of Algorithms
Quicksort challenges

Quicksort 1 - Partition
Quicksort 2 - Sorting
Quicksort In-place (advanced)
Running time of Quicksort
Counting sort challenges

Counting Sort 1 - Counting
Counting Sort 2 - Simple sort
Counting Sort 3 - Preparing
Full Counting Sort (advanced)
There will also be some challenges where you'll get to apply what you've learned using the completed algorithms.

About the Challenges
Each challenge will describe a scenario and you will code a solution. As you progress through the challenges, you will learn some important concepts in algorithms. In each challenge, you will receive input on STDIN and you will need to print the correct output to STDOUT.

There may be time limits that will force you to make your code efficient. If you receive a "Terminated due to time out" message when you submit your solution, you'll need to reconsider your method. If you want to test your code locally, each test case can be downloaded, inputs and expected results, using hackos. You earn hackos as you solve challenges, and you can spend them on these tests.

For many challenges, helper methods (like an array) will be provided for you to process the input into a useful format. You can use these methods to get started with your program, or you can write your own input methods if you want. Your code just needs to print the right output to each test case.

Sample Challenge
This is a simple challenge to get things started. Given a sorted array () and a number (), can you print the index location of  in the array?

Example



Return  for a zero-based index array.

If you are going to use the provided code for I/O, this next section is for you.

Function Description

Complete the introTutorial function in the editor below. It must return an integer representing the zero-based index of .

introTutorial has the following parameter(s):

int arr[n]: a sorted array of integers
int V: an integer to search for
Returns

int: the index of  in 
The next section describes the input format. You can often skip it, if you are using included methods or code stubs.

Input Format

The first line contains an integer, , a value to search for.
The next line contains an integer, , the size of . The last line contains  space-separated integers, each a value of  where .

The next section describes the constraints and ranges of the input. You should check this section to know the range of the input.
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int introTutorial(int V, vector<int> arr) {
  return std::distance(arr.begin(), std::find(arr.begin(), arr.end(), V));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string V_temp;
    getline(cin, V_temp);

    int V = stoi(ltrim(rtrim(V_temp)));

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

    int result = introTutorial(V, arr);

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
