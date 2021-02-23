#include <iostream>
using namespace std;

int main(){
    int n,fibonacciTerm,firstno=1,secondno=1,nextNo;
    cin>>n;
    if(n==1 || n==2){
        fibonacciTerm=1;
    }else{
        for(int i=3; i<=n;i++){
            nextNo=firstno+secondno;
            firstno=secondno;
            secondno=nextNo;
        }
    }
    fibonacciTerm=nextNo;
    cout<<fibonacciTerm;


}
