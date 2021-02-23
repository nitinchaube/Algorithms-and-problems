/*StairCase Problem
Send Feedback
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274

*/



#include <iostream>
using namespace std;
int staircase(int n,long* arr=new long[72]()){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(arr[n]>0){
        return arr[n];
    }
    int step3=staircase(n-3,arr);
    int step2=staircase(n-2,arr);
    int step1=staircase(n-1,arr);
    int ans=step1+step2+step3;
    arr[n-3]=step3;
    arr[n-2]=step2;
    arr[n-1]=step1;
    return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
