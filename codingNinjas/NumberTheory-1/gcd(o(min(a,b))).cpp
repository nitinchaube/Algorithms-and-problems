#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    int gcd=INT_MAX;
    for(int i=1;i<min(a,b);i++){
        if(((a%i) ==0 )&&((b%i) ==0)){
                gcd=i;
           }
    }
    return gcd;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}
