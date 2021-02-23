#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    for(int i=2;i<=N;i++){
        if(N==0 || N==1){
            break;
        }
        for(int j=2;j<=i;j++){
            if(i%j==0){
                if(i==j){
                    cout<<i<<endl;
                }
                break;
            }
        }
    }
}
