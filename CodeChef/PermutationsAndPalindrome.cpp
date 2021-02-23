#include<bits/stdc++.h>
using namespace std;

char getChar(int i){
    return (char)(i+97);
}
void printPalindromicString(string s){
    map<char, vector<int> > freq;
    for(int i=0;i<s.size();i++){
        freq[s[i]].push_back(i);
        //cout<<freq[s[i]][i]<<endl;

    }

    int odd_freq_count=0;
    for(int i=0;i<26;i++){
        if((freq[getChar(i)].size() % 2)!=0){
            odd_freq_count++;
        }
    }
    if(odd_freq_count>=2){
        cout<<"-1";
        return;
    }
    int ans[s.size()];
    int start=0;
    int endi=s.size()-1;
    for(int i=0;i<26;i++){
        char currentChar=getChar(i);
        for(int j=0;j<freq[currentChar].size();j+=2){
            if((freq[currentChar].size() - j)==1){
                ans[s.size()/2] = freq[currentChar][j];
                continue;
            }
            ans[start]=freq[currentChar][j];
            ans[endi]=freq[currentChar][j+1];

            start++;
            endi--;
        }
    }
    for(int i=0;i<s.size();i++){
        cout<<ans[i]+1<<" ";
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        printPalindromicString(s);
        cout<<endl;
    }
    return 0;

}
