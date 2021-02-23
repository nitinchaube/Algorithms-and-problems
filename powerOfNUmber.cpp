# include <iostream>
using namespace std;

int main(){
int x,n,i=1,c=1;
    cin>>x>>n;
    while(i<=n){
        c=c*x;
        i++;
    }
    cout<<c;
}
