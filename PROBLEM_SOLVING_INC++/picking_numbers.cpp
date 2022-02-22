/**Given an array of integers, find the longest subarray where the absolute difference between any two elements is less than or equal to .

Example

There are two subarrays meeting the criterion:  and . The maximum length subarray has  elements.

Function Description

Complete the pickingNumbers function in the editor below.

pickingNumbers has the following parameter(s):

int a[n]: an array of integers
Returns

int: the length of the longest subarray that meets the criterion
Input Format

The first line contains a single integer , the size of the array .
The second line contains  space-separated integers, each an .

Constraints

The answer will be .
Sample Input 0

6
4 6 5 3 3 1
Sample Output 0

3*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pickingNumbers(vector<int> arr, int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
		int temp = 0;
        sort(arr.begin(), arr.end());
		for(int j = i; j < n; j++)
		{
			if( abs(arr[i] - arr[j]) <= 1)
				temp++;
			else
				break;
		}
		if(temp > count)
			count = temp;
    }
	return count;
}

int main ()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = pickingNumbers(arr, n);

    cout << result;

    return 0;
}
