/*Number Of Balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/





#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int balancedBTs(int h){
    if(h==0 || h==1){
        return 1;
    }
    ll m=pow(10,9)+7;
    ll x=balancedBTs(h-1);
    ll y=balancedBTs(h-2);
    ll ans=(x*x)+(2*x*y);
    /*long res1=(long)x*x;
    long res2=(long)x*y*2;
    int ans1=(int)res1%m;
    int ans2=(int)res2%m;

    int ans=(ans1+ans2)%m;*/
    return ans%m;
}

int main(){
    int h=8;
    cout<<balancedBTs(h)<<endl;
    return 0;
}
