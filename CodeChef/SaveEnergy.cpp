/*Save Energy Problem Code: SVENGY
Add problem to Todo list
Submit


There are N towns in a line, numbered from 0 to N - 1. Starting from town 0, we want to reach town N - 1. From town i, we can jump to any town j > i with an energy cost of (j-i)*A[i] + (j2 - i2)*A[i]2, where A[i] for all i are given in input.

Find the minimum total energy cost to reach town N - 1 from town 0.

Input

The first line contains a single integer, N.
The next line contains N space separated integers, ith integer denoting the value of A[i] , 0 ≤ i ≤ N - 1.
Output
Output the minimum cost to reach town N.

Constraints
1 ≤ N ≤ 105
-103 ≤ A[i] ≤ 103
Example 1

Input:
5
1 -1 2 2 2

Output:
14
Example 2

Input:
4
2 2 3 4

Output:
42  */

//COST =   (j-i)*A[i] + (j2 - i2)*A[i]2

/*LOGIC:
    so for i to go to k(last number) it can directly jump or can go to j and then to k.
    so for achieving this ,it should satisfy this equation :
        (j-i)*A[i] + (j2 - i2)*A[i]2<=(k-i)*A[i] + (k2 - i2)*A[i]2
            :
            :
            :
        A[j]+(k+j)A[j]2<=A[i]+(k+j)A[i]2
        since k+j is common
        so all depends on A[j] and A[i]
        so if A[j]<A[i] || (A[i]==A[j] && A[i]>0) then we can take the path via j i.e i to j to k.
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int minimumcost(ll *A,ll n){

    ll cost=0;
    ll curr=0;
    while(curr<n-1){
        ll next=curr+1;
        while(next<n-1){
            if((abs(A[curr])>abs(A[next])) || (((abs(A[curr])==abs(A[next])) && (A[curr]>0) ))){
                break;
            }else{
                next++;
            }

        }
        cost+=(next-curr)*A[curr] + (next*next -curr*curr)*A[curr]*A[curr];
        curr=next;
    }
    return cost;
}

int main(){
    ll n;
    cin>>n;
    ll *A=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>A[i];
    }
    ll cost=minimumcost(A,n);
    delete []A;
    cout<<cost;

}
