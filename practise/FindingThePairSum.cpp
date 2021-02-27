/*
Given an array A[] and a number x, find the pair in A[] with sum as x
*/

#include<bits/stdc++.h>
using namespace std;

void findPairs(int *arr, int n,int sum){
    unordered_set<int> s;

    for(int i=0;i<n;i++){
        int temp=sum-arr[i];
        if(s.find(temp) != s.end()){
            cout<<arr[i]<<" "<<temp<<endl;
        }
        s.insert(arr[i]);
    }
}

int main(){
    int n,sum;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>sum;


    findPairs(arr,n,sum);
}
