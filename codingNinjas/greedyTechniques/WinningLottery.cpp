#include<bits/stdc++.h>
using namespace std;

void lottery(int s,int d){
    int *a=new int[d];

    for(int i=0;i<d;i++){
        a[i]=0;
    }
    a[0]=1;
    s-=1;
    for(int i=d-1;i>=0;i--){
        if(i==0){
            a[i]+=s;
        }
        if(s<=9){
            a[i]+=s;
            s=0;
        }else if(s>9){
            a[i]=9;
            s-=9;
        }
    }
    for(int i=0;i<d;i++){
        cout<<a[i];
    }
    delete[] a;
}

int main(){
    int s,d;
    cin>>s>>d;
    lottery(s,d);
}
