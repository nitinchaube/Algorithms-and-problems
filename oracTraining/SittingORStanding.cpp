#include<bits/stdc++.h>
using namespace std;
 int main(){
    freopen("sitin.txt","r",stdin);
    freopen("sitout.txt","w",stdout);


    int n,s;
    cin>>n>>s;

    int nos=n*s;
    int tickets;
    cin>>tickets;
    if(nos>=tickets){
        cout<<tickets<<" "<<0<<endl;
    }else{
        cout<<nos<<" "<<tickets-nos<<endl;
    }

    return 0;
 }
