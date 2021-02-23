#include<bits/stdc++.h>
using namespace std;

void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}

bool arrayIsSorted(int *arr,int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}



bool check(int *arr,int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]-arr[i+1]==1){
            swap(arr[i],arr[i+1]);
        }
    }
     if(arrayIsSorted(arr,n)){
            return true;
    }
    return false;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int* arr =new int[n];
    	for(int i=0;i<n;i++){
            cin>>arr[i];

        }
        if(check(arr,n)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }



    }

}
