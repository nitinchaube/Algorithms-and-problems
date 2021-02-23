#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> i1, pair<int, int> i2)
{
	return i1.second<i2.second;
}
int activityCounter(pair<int,int>*a,int n){
    int count=1;
    int currentfinishTime=a[0].second;
    for(int i=1;i<n;i++){
        if(currentfinishTime<=a[i].first){
            count+=1;
            currentfinishTime=a[i].second;
        }
    }
    return count;

}
int main()
{
    //Write your code here
    int n;
    cin>>n;
    pair<int,int> *arr=new pair<int,int>[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+n,compare);
    cout<<activityCounter(arr,n)<<endl;
    return 0;
}
