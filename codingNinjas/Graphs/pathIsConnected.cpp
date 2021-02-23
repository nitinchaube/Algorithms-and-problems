
/* Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3
0 3
Sample Output 2:
false
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn�t any path from vertices 0,1,3 to vertex 2.  */


#include<bits/stdc++.h>
using namespace std;
void DFS(int **edges,int n,bool* visited,int sv){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(sv!=i && !visited[i] && edges[sv][i]==1){
            DFS(edges,n,visited,i);
        }
    }

}
bool isConnected(int **edges,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int sv=0;
    visited[sv]=true;
    DFS(edges,n,visited,sv);
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            return false;
        }
    }
    return true;
}
int main(){
    int n,e;
    cin>>n>>e;
    int **edges = new int *[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }

    if(isConnected(edges,n)){
        cout<<"true";
    }else{
        cout<<"false";
    }


}
