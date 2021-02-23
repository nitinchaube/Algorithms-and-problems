#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<fib;
}

//METHOD 1 :- RECURSION METHOD t(n)=O(2^n)
int fib(int n){
    if(n==0 ||n=1){

        return 1;
    }
    return fib(n-1)+fib(n-2);
}

//METHOD 2 :- RECURSION USING AN ARRAY t(n)=O(n)

int fib(int n,int *arr){
    if(n==0 || n==1){
        return 1;

    }
    if(arr[n]>0){
        return arr[n];
    }
    int output=fib(n-1,arr)+fib(n-2,arr);
    arr[n]=output;
    return output;
}

//METHOD 3 :- USING ITERATION IN array

int fib(int n){
    int *arr=new int[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=0;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    int output=arr[n];
    delete [] arr;
    return output;
}






