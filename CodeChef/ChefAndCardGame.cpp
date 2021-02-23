#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int T;
    cin>>T;
    while(T-- > 0){
        int N;
        cin>>N;
        int chef=0,monty=0;
        while(N-- >0){
            ll a,b;
            cin>>a>>b;
            ll c=0;
            while(a){
               int b=a%10;
               c+=b;
               a=a/10;
            }
            ll m=0;
            while(b){
                int d=b%10;
                m+=d;
                b=b/10;
            }
            if(c>m){
                chef++;
            }else if(m>c){
                monty++;
            }else{
                chef++;
                monty++;
            }
        }
        if(chef>monty){
            cout<<"0"<<" ";
        }
        else if(monty>chef){
            cout<<"1"<<" ";
        }
        else if(chef==monty){
            cout<<"2"<<" ";
        }
        cout<<max(chef,monty)<<endl;
    }
    return 0;
}
