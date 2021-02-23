#include<bits/stdc++.h>
using namespace std;

//METHOD 1 problem is that it runs for exponential time and there are repettion of functions
int numcodes(int *n,int size){
    if(size==1){  //eg "1" i.e a
        return 1;
    }
    if(size==0){    //eg "" i.e empty array
        return 1;
    }
    int output=numcodes(n,size-1);
    if((n[size-2]*10)+n[size-1] <=26){
        output+=numcodes(n,size-2);
    }
    return output;
}

//METHOD 2 for the problem of method 1

int numcodes(int *n,int size,int* arr){

     if(size==1){  //eg "1" i.e a
        return 1;
    }
    if(size==0){    //eg "" i.e empty array
        return 1;
    }
    if(arr[size>1]){ // checking if the function is already  repeated or not if repeated means >1 in arr so return the arr elment rather than recursively calling the function again
        return arr[size];
    }
    int output=numcodes(n,size-1);
    if((n[size-2]*10)+n[size-1] <=26){
        output+=numcodes(n,size-2);
    }
    arr[size]=output;
    return output;
}
  //METHOD  3: iteration method
int numcodes(int * input,int size){
    int *output =new int[size+1];
    output[0]=1;
    output[1]=1;
    for(int i=2;i<=size;i++){
        output[i]=output[i-1];
        if((output[i-2]*10)+output[i-1] <=26){
            output[i]+=output[i-2];
        }
    }
    int ans=output[size];
    delete [] output;
    return ans;
}

int main(){
  ////input taken and passed for function
}
