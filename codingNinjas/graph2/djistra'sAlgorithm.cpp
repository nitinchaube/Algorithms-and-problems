/*
Dijkstra's Algorithm
Send Feedback
ID: 1725

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/


#include<bits/stdc++.h>
using namespace std;

int get_min_vertex(bool *visited,int *distance,int n){
    int min_vertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (min_vertex==-1 || distance[i]<min_vertex)){
            min_vertex=i;
        }
    }
    return min_vertex;
}

void djistra(int **edges,int n){
    int *distance=new int[n];
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<n-1;i++){
        int min_vertex=get_min_vertex(visited,distance,n);
        visited[min_vertex]=true;
        for(int j=0;j<n;j++){
            if(!visited[j] && edges[min_vertex][j]!=0){
                if(distance[j] > (distance[min_vertex]+edges[min_vertex][j])){
                    distance[j]=distance[min_vertex]+edges[min_vertex][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }

}

int main()
{
    int n,v;
    cin>>n>>v;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<v;i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        edges[src][dest]=wt;
        edges[dest][src]=wt;
    }
    djistra(edges,n);

    for(int i=0;i<n;i++){
        delete []edges[i];
    }
    delete []edges;

}
