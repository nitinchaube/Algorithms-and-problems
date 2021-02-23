#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int a,n,b,c=0,i=1,live,prev;
    bool isdec=true;
    cin>>a;
    cin>>n;
    prev=n;

    while(i<a){
        cin>>b;
        live=b;
        if(prev==live){
            isdec=false;
            cout<<"false";
            break;
        }else if(prev<live){
            isdec=false;
            prev=live;
        }else if(prev>live){
            if(isdec==false){
                cout<<"false";
                break;
            }else{
                prev=live;
            }

        }
        i++;
    }
    if(isdec==true){
        cout<<"true";
    }
	if(isdec==false && i==a){
        cout<<"true";
    }

}
