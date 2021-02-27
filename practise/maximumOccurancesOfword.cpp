#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;

void findMaximumOccurances(string s){
    unordered_map<string,int> m;
    stringstream ss(s);
    string word;
    while(ss >> word){
        m[word]+=1;


    }
    unordered_map<string,int> :: iterator it;
    string maxit;
    int maxi=0;
    for(it=m.begin();it!=m.end();it++){
        if(it->second > maxi){
            maxit=it->first;
            maxi=it->second;
        }
    }
    cout<<maxit<<" "<<maxi;

}

int main(){
    string s;
    getline(cin, s);


    findMaximumOccurances(s);
}



