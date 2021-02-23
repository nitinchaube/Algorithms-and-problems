/*Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job.
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct Job{
    ll st,ft,p;
};
bool compare(Job a,Job b){
    return a.ft<b.ft;
}
ll binarySearch(Job jobs[], int index)
{
    int lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].ft <= jobs[index].st)
        {
            if (jobs[mid + 1].ft <= jobs[index].st)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
    return -1;
}
ll maximumProfit(Job *arr,ll n){
    ll *dp=new ll[n] ;
    sort(arr,arr+n,compare);
    dp[0]=arr[0].p;
    for(ll i=1;i<n;i++){
        ll including=arr[i].p;
        ll lNconflict=-1;
        /*for(ll j=i-1;j>=0;j--){
            if(arr[j].ft<=arr[i].st){
                lNconflict=j;
                break;
            }  THIS METHOD GIVES ME IN O(N^2) TIME
        }*/
        lNconflict=binarySearch(arr,i);  //THIS ONE GIVES IN O(NLOGN) TIME

        if(lNconflict!=-1){
            including+=dp[lNconflict];

        }
        dp[i]=max(including,dp[i-1]);

    }
    ll ans=dp[n-1];
    delete []dp;
    return ans;
}

int main(){
    ll n;
    cin>>n;
    Job arr[n];

    for(ll i=0;i<n;i++){
        cin>>arr[i].st>>arr[i].ft>>arr[i].p;
    }
    cout<<maximumProfit(arr,n);
}
