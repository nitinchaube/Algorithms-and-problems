# include <iostream>
using namespace std;
int main(){
    int N,even_sum=0,odd_sum=0,c;
    cin>>N;
    while(N!=0){
         c= N%10;
        if(c%2==0){
            even_sum+=c;
        }else{
            odd_sum+=c;
        }
        N=N/10;


    }
    cout<<even_sum<<" "<<odd_sum;
}
