
# include <iostream>
using namespace std;
int main()
{
      int n;
    cin>>n;
     int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     int sumOdd=0,sumEven=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==0 && i%2==0){
            sumEven+=a[i];
        }else if(i%2!=0 && a[i]%2!=0){
            sumOdd+=a[i];
        }
    }
    cout<<sumEven<<" "<<sumOdd<<endl;




}
