/*Problem discussion
Send Feedback
Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value by modifying the array under the condition that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help
Input Format
The First line contains two space-separated integers: N,K
Next lines contain N space-separated integers denoting elements of the array
Output Format
The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array
Constraints
1 =< N <= 10^5
1 <= Ai,K <= 10^9
Sample Input1:
3 6
1 15 10
Sample Output1:
5
Explaination
We change from 1 to 6, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference.
*/



#include<bits/stdc++.h>
using namespace std;

void minimizeSum(int *a,int n,int k){
    int big=a[n-1]-k;
    int small=a[0]+k;
    int ans=a[n-1]-a[0];
    if(big<small){
        int temp=small;
        small=big;
        big=small;
    }
    for(int i=1;i<n-1;i++){
        int sub=a[i]-k;
        int add=a[i]+k;
        if(add<=big || sub>=small){
            continue;
        }
        if(add-small>big-sub){
            small=sub;
        }else{
            big=add;
        }
    }
    cout<<min(ans,big-small);
}

int main(){
    int n,k;
    cin>>n>>k;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    minimizeSum(a,n,k);

    delete[] a;
}
