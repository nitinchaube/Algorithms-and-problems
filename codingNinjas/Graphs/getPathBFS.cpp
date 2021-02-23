/*Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/





#include<bits/stdc++.h>
using namespace std;


void getPathBFS(int **edges,int n,bool *visited,int v1,int v2,queue<int> &q){
    visited[v1]=true;
    q.push(v1);
    map<int,int>m;
    while(!q.empty()){
        int current=q.front();
        if(current==v2){
            break;
        }
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[current][i]==1 && current!=i){
                q.push(i);
                visited[i]=true;
                m[i]=current;
            }
        }
        q.pop();
        if(q.empty()){
            return;
        }
    }
    int i=v2;
    cout<<v2<<" ";
    while(i!=v1){
        cout<<m[i]<<" ";
        i=m[i];
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
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    int v1,v2;
    cin>>v1>>v2;
    queue<int> q;
    getPathBFS(edges,n,visited,v1,v2,q);


}
