#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    map<char,int> m;
     m.insert(pair<char, int>('a', 0));
    m.insert(pair<char, int>('s', 0));
    m.insert(pair<char, int>('p', 0));
    map<char,int> :: iterator it;
    for(int i=0;i<n;i++){
        m[str[i]]=m[str[i]]+1;
    }
    for(it=m.begin();it!=m.end();it++){
        if(it->first=='a'){
            cout<<it->second<<' ';
        }
        else if(it->first=='s'){
            cout<<it->second<<' ';
        }
         else if(it->first=='p'){
            cout<<it->second<<' ';
        }
    }


	return 0;
}
