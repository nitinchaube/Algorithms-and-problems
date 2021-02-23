/*
Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
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
1 2 1
0 1 3
0 3 5
*/

#include<bits/stdc++.h>
using namespace std;

class edge{

    public:
        int src;
        int dest;
        int weight;


};
bool compare(edge a,edge b){
    return a.weight<b.weight;
}

int getParent(int v,int* parent){
    if(parent[v]==v){ // v has no parent ie v is parent of itself
        return v;
    }
    getParent(parent[v],parent); //Finding the topmost parent
}

edge *kruskal(edge *edges,int n,int e){
    sort(edges,edges+e,compare);  //Sorting the array in increasing order of its weight
    int *parent =new int[n];        //parents array for storing the parents of element
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    edge* output=new edge[n-1];

    int count=0;
    int i=0;
    while(count<(n-1)){
        edge curr_edge=edges[i];
        int srcParent=getParent(curr_edge.src,parent);
        int destParent=getParent(curr_edge.dest,parent);
        if(srcParent!=destParent){
            output[count]=curr_edge;
            count++;
            parent[srcParent]=destParent;
        }
        i+=1;
    }
    return output;
    return output;

}


int main(){
    int n,e;
    cin>>n>>e;

    edge *edges=new edge[e];
    for(int i=0;i<e;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
    }
    edge *output=kruskal(edges,n,e);
    for(int i=0;i<n-1;i++){
        if(output[i].src < output[i].dest){
            cout<< output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }

    }


}
