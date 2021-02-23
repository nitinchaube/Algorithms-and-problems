#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    //special case
    if(a<b){
        return gcd(b,a);
    }
    //base case
    if(b==0){
        return a;
    }
    //recursion
    return gcd(b,a%b);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}
