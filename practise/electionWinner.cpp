/*
Given an array of names of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidates received Max vote. If there is tie, print lexicographically smaller name.

Examples:

Input :  votes[] = {"john", "johnny", "jackie",
                    "johnny", "john", "jackie",
                    "jamie", "jamie", "john",
                    "johnny", "jamie", "johnny",
                    "john"};
Output : John
We have four Candidates with name as 'John',
'Johnny', 'jamie', 'jackie'. The candidates
John and Johny get maximum votes. Since John
is alphabetically smaller, we print it.
*/

#include<bits/stdc++.h>
using namespace std;

int winnerOfElection(vector<string>& votes){
    unordered_map<string,int>m;
    vector<string>::iterator i;
    for (auto& str : votes)
        {
            m[str]++;
        }
    int maxvalue=0;
    string winner;
    unordered_map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        if(it->second > maxvalue){
            maxvalue=it->second;
            winner=it->first;
        }
        if(it->second == maxvalue && it->first < winner){
            winner=it->first;
        }
    }
    cout<<winner;
}

int main() {
    vector<string> votes;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        votes.push_back(s);
    }
    winnerOfElection(votes);
}
