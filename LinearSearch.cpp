#include <iostream>
using namespace std;

int LinearSearch(int arr[],int n,int x){
    int i=0;
    for(i=0;i<n-1;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main() 
{
    int arr[]={3,5,4,1,2,8,9,7};
    int x=5;
    int n= sizeof(arr)/sizeof(arr[0]);
    cout <<  x  <<"is present at index"<<LinearSearch(arr , n, x);
    return 0;
} 