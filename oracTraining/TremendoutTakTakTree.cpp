#include<bits/stdc++.h>
using namespace std;


bool candistributeEqually(int fruits){
    if(fruits%11==1){
        return true;
    }else{
    return false;
    }
}

int main(){
    freopen("taktakin.txt","r",stdin);
    freopen("taktakout.txt","w",stdout);

    int fruits;
    cin>>fruits;

    int fullmoon=0;

    while(!candistributeEqually(fruits)){
        fullmoon+=1;
        fruits=2*fruits;
    }

    cout<< fullmoon<<" "<<fruits<<endl;


    return 0;
}
