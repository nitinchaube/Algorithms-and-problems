#include<bits/stdc++.h>
using namespace std;

void makeSieve(int i,int n,bool *dp){
    if(dp[i]){
        for(int j=i*i;j<=n;j+=i){
            dp[j]=false;
        }
    }

}

int main(){
    int n;
    cin>>n;
    bool *dp=new bool[n+1];
    dp[0]=dp[1]=false;
    for(int i=2;i<=n;i++){
        dp[i]=true;
    }
    for(int i=2;i*i<=n;i++){
       makeSieve(i,n,dp);
    }
    int count=0;
    for(int i=0;i<=n;i++){
        if(dp[i]==true){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
