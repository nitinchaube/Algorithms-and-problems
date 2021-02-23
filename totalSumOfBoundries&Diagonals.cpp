#include<bits/stdc++.h>
using namespace std;

int main(){

int N,t;


int sum;
cin>>t;
for(int z=0;z<t;z++){
    sum=0;
    cin>>N;
    int a[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                sum=sum+a[i][j];
            }

            if(i==0 && j!=0){
                sum=sum+a[i][j]+a[j][i];
            }
            if(i==N-1 && j!=0 && j!=N-1){
                sum=sum+a[i][j]+a[j][i];
            }
            if(i!=j && (i==N-j-1) && i!=0 && j!=0){
                sum=sum+a[i][j];
            }
        }
    }
    cout<<sum;
}

}
