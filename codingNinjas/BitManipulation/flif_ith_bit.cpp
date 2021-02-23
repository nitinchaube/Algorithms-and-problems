#include<bits/stdc++.h>
using namespace std;


int flifIthbit(int n,int i){
    int x=1<<i;
    int xOred=n^x;
    cout<<xOred;
}
int main(){
    int n,i;
    cin>>n>>i;
    flifIthbit(n,i);
}
