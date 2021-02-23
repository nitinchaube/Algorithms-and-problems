#include<iostream>
using namespace std;

int power(int x,int n){
    if(n==0){
        return 1;
    }

	return(x*power(x,n-1));

}
int main() {
	// Write your code here
	int x,n;
    cin>>x>>n;
    int ans;
    ans=power(x,n);
    cout<<ans;
}
