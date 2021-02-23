/*Turn off 1st set bit
Send Feedback
You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Integer N
Output Format :
Updated N
Sample Input 1 :
4
Sample Output 1 :
0
Sample Input 2 :
12
Sample Output 2 :
8
*/


#include <iostream>
using namespace std;


int turnOffFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n==0)
    {
        return 0;
    }
    int i=0;
    while((n&(1<<i))==0)
    {
        i++;
    }
    int ans=(n^(1<<i));
    return ans;
}

int main() {
	int n;

	cin >> n;

	cout<< turnOffFirstSetBit(n) <<endl;

	return 0;
}

