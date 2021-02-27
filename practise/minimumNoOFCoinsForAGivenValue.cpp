#include<bits/stdc++.h>
using namespace std;


int minimumCoin(int *coins,int n, int v){
    int table[v+1];

    table[0]=0;
    for(int i=1;i<=v;i++){
        table[i]=INT_MAX;
    }

    for(int i=1;i<=v;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                int remaining=table[i-coins[j]];
                if(remaining!=INT_MAX && remaining+1 < table[i]){
                    table[i]=remaining+1;
                }
            }
        }
    }
    if(table[v]==INT_MAX){
        return -1;
    }
    return table[v];
}

int main()
{
    int coins[]={25,10,5};
    int n=sizeof(coins)/sizeof(coins[0]);
    int v=30;
    cout<<minimumCoin(coins,n,v);
}
