#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
bool findAttackORDefend(char arr[],int x,int y){

    map<char,int>m;
    int count=0;
    for(int i=x;i<=y;i++){
        m[arr[i]]=m[arr[i]]+1;
    }
    map<char,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        if(it->second==1){
            count++;
        }
    }
    if(count%2==0){
        return false;
    }else{
        return true;
    }


}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int L;
    cin>>L;
    string str;
    getline(cin,str);
    char arr[L-1];
    for(int i=0;i<L-1;i++){
        arr[i]=str[i];
    }

    int t;
    int attack=0,defend=0;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
         if(findAttackORDefend(arr,x,y)){
            attack++;
         }else{
             defend++;
         };
    }
    if(attack > defend){
        cout<<"DEFEND";
    }else{
        cout<<"AIRSTRIKE";
    }

    return 0;
}
