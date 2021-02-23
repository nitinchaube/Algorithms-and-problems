#include<iostream>
# include<cmath>
using namespace std;
int main(){
    int N,i=0,total=0,b=0;
    cin>>N;
    while(N!=0){
         b=N%10;
        total=total+b*pow(2,i);
        i++;
        N=N/10;
    }
    cout<<total;


}
