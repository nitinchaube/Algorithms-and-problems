#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
void print(unordered_set<unordered_set<int>*>* components){
    unordered_set<unordered_set<int>*>:: iterator it1=components->begin();
    while(it1 != components->end()){
        unordered_set<int>* component=*it1;
        unordered_set<int> ::iterator it2=component->begin();
        while(it2 != component->end()){
            cout<<*it2+1<<" ";
            it2++;
        }
        cout<<endl;
        delete component;
        it1++;
    }
}
*/

void dfs(vector<int>* edges,int start,unordered_set<int>* component,bool* visited){
    visited[start]=true;
    component->insert(start);
	for(int i=0;i<edges[start].size();i++){
        int next=edges[start][i];
        if(!visited[next]){
            dfs(edges,next,component,visited);
        }
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges,int n){
    bool* visited=new bool[n];      // for visited elements
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            unordered_set<int>* component=new unordered_set<int>();  //here one whole connected component will be stored;
            dfs(edges,i,component,visited);                           //all the vertices of a one component wil be stored in component set
            output->insert(component);                              //we are inserting the one component set in output set
        }
    }
    delete []visited;
    return output;

}

int main(){

    int n;
    cin>>n;
    vector<int>*edges=new vector<int>[n]; //ARRAY OF VECTORS FOR ADJACENCY LIST   E.G. [V1,V2,V3]
    int e;
    cin>>e;
    for(int i=0;i<e;i++){       //CREATING ADJACENCY LIST
        int j,k;
        cin>>j>>k;
        edges[j-1].push_back(k-1);
        edges[k-1].push_back(j-1);
    }

    unordered_set<unordered_set<int>*>* components=getComponents(edges,n);  //int this a set of all components will be stored
    unordered_set<unordered_set<int>*>::iterator it1=components->begin();
    while(it1 != components->end()){
        unordered_set<int>* component=*it1;
        unordered_set<int> ::iterator it2=component->begin();
        while(it2 != component->end()){
            cout<<*it2 + 1 <<" ";
            it2++;
        }
        cout<<endl;
        delete component;
        it1++;
    }
    delete components;
    delete edges;



}
/*6
5
1 2
1 4
2 3
3 4
5 6
*/
