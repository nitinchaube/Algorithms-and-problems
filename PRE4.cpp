#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    for(int i=0;i<n/2;i++){
        int N=a[i]+a[n-i-1];
        cout<<N/10<<" "<<N%10<<endl;
    }
	return 0;
}
