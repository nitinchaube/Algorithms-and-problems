#include<bits/stdc++.h>
using namespace std;


int checkbit(int n,int i){


    if((n&1)==0){
        cout<<"even";
    }else{
        cout<<"odd";
    }
}
int main(){
    int n,i;
    cin>>n>>i;
    checkbit(n,i);
}
