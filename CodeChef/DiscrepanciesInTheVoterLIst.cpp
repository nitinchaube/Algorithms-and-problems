#include<bits/stdc++.h>
using namespace std;

vector<int> getVoters(int a[],int N){
    sort(a,a+N);
    vector<int>voters;
    for(int i=0;i<N;){
        int count=0;
        int j=i;
        while(j<N && (a[j]==a[i]){
            count++;
            j++;
        }
        if(count>1){
            voters.push_back(a[i]);
        }
        i=j;
    }
    return voters;
}
int main(){
    int N1,N2,N3;
    cin>>N1>>N2>>N3;
    int N=N1+N2+N3;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    vector<int> voters= getVoters(a,N);

    cout<<voters.size()<<endl;
    for(int i=0;i<voters.size();i++){
        cout<<voters[i]<<endl;
    }

}
