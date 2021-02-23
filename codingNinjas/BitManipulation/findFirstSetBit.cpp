/*Find first set bit
Send Feedback
You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
Input Format :
Integer N
Output Format :
Integer M
Sample Input 1 :
7
Sample Output 1 :
1
Sample Input 2 :
12
Sample Output 2 :
4
*/


#include <iostream>
using namespace std;


int returnFirstSetBit(int n){
    if(n==0){
        return 0;
    }
    int i=0;
    for( i=0;n&(1<<i)==0;){
        i++;
    }
    int ans= 1<<i;
    return ans;
}
int main() {
	int n;

	cin >> n;

	cout<< returnFirstSetBit(n) <<endl;

	return 0;
}
