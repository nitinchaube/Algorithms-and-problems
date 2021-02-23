/*Min. Absolute Difference In Array
Send Feedback
Given an integer array A of size N, find and return the minimum absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)
Output Format :
Minimum difference
Constraints :
1 <= N <= 10^6
Sample Input :
5
2 9 0 4 5
Sample Input :
1
*/

#include<bits/stdc++.h>
using namespace std;
#include<climits>

int mod(int a)
{
	if(a<0)
	{
		return -a;
	}
	return a;
}
int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
std::sort(arr, arr+n);
	int i=0;
	int j=1;
	int minimum=INT_MAX;
	while(j<n)
	{
		if(mod(arr[i]-arr[j])<minimum)
		{
			minimum=mod(arr[i]-arr[j]);
		}
		i++;
		j++;
	}
	return minimum;
}



int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	cout<< minAbsoluteDiff(input,size) << endl;

	return 0;

}
