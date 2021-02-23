#include<bits/stdc++.h>
using namespace std;

void visitTheConnectedOne(int **edges,int n,bool *visited,int sv){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(sv!=i && edges[sv][i]==1 && !visited[i] ){
            visitTheConnectedOne(edges,n,visited,i);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            visitTheConnectedOne(edges,n,visited,i);
        }
    }
	cout<<count;

}
