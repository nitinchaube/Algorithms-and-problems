#include<iostream>
using namespace std;
int main(){
    unsigned long long int N,c=1,b=0;

    cin>>N;
    while(N!=0){

        b=b+(N%2)*c;
        c=c*10;



        N=N/2;
    }
    cout<<b;


}
