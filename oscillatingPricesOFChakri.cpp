
#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int N,j;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];

    }
    int profit=0;
    for(int i=0;i<N;i++){
        for( j=i;j<N;j++){
            if(profit<(a[j]-a[i])){
                profit=a[j]-a[i];
            }
        }
    }
    cout<<profit;
}
