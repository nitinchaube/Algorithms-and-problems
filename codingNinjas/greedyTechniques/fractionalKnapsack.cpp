#include<bits/stdc++.h>
using namespace std;
#define ll long long int;

struct Item{
    ll value,weight;
};
bool compare(struct Item a, struct Item b){
    value1=(double)a.value/(a.weight);
    vlaue2=(double)b.value/(b.weight);
    return value1>value2;
}

double fractionalKnapsack(struct Item *arr,ll w,ll size){
    sort(arr,arr+size,compare);
    ll currW=0;
    double fvalue=0;

    for(int i=0;i<size,i++){
        if(currW+arr[i].weight<=W){
            currW+=arr[i].weight;
            fvalue+=arr[i].value;
        }else{
            int RWeight=w-currW;
            fvalue+=arr[i].value*((double)RWeight/(arr[i].weight));
            break;
        }
    }
    return fvalue;
}

int main(){
    ll w=50;
    Item arr[]={{60,20},{70,15},{80,40}};
    cout<<"Maximum value is"<<fractionalKnapsack(arr,w,3);
}
