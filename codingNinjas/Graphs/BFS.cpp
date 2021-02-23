#include<bits/stdc++.h>
using namespace std;

void print(int **edges,int n,int sv,bool *visited,queue<int> &q){
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
            int s=q.front();
            q.pop();
            cout<<s<<endl;
            for(int i=0;i<n;i++){
                    if(i==s){
                        continue;
                    }
                    if(edges[s][i]==1 && !visited[i]){
                        q.push(i);
                        visited[i]=true;

                    }

            }

        }


}

void BFS(int **edges,int n){
    bool *visited=int bool[n];
    for (int i=0;i<n;i++){
        visited[i]==false;
    }
     queue<int>q;
    for (int i=0;i<n;i++){
        if(!visited[i]){
            print(edges,n,i,visited,q)
        }

    }
}

int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int *[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }


    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    BFS(edges,n);



    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete[] edges;



}
