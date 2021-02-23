/*Largest Piece
Send Feedback
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/


#include<bits/stdc++.h>
using namespace std;
/*
int dfs(vector<vector<int>>&cake,int n,int i,int j,bool **visited){
    visited[i][j]=true;
    int ans=0;
    //left element
    if(j-1>=0){
        if(!visited[i][j-1] && cake[i][j-1]==1){
            ans+=dfs(cake,n,i,j-1,visited);
        }
    }
    //right element
    if(j+1<n){
        if(!visited[i][j+1] && cake[i][j+1]==1){
            ans+=dfs(cake,n,i,j+1,visited);
        }
    }
    //top element
    if(i-1>=0){
        if(!visited[i-1,j] && cake[i-1][j]==1){
            ans+=dfs(cake,n,i-1,j,visited);
        }
    }
    // down element
    if(i+1<n){
        if(!visited[i+1,j] && cake[i+1][j]==1){
            ans+=dfs(cake,n,i+1,j,visited);
        }
    }

    return 1+ans;

}
int getBiggestPieceSize(vector<vector<int>>cake,int n){
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j]=false;
        }
    }
    int max_piece=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j]==1 && !visited[i][j]){
                visited[i][j]=true;
                int ans=dfs(cake,n,i,j,visited);
                if(ans>max_piece){
                    max_piece=ans;
                }
            }
        }
    }
    return max_piece;
}*/
int dfs_run(vector<vector<int>> &cake,int n,int **visited,int i,int j){
    visited[i][j]=1;
    // check left
    int ans=0;
    if(j-1>=0){
        if(cake[i][j-1]==1&&visited[i][j-1]==0){
            ans+=dfs_run(cake,n,visited,i,j-1);
        }
    }
    // check right
    if(j+1<n){
        if(cake[i][j+1]==1&&visited[i][j+1]==0){
            ans+=dfs_run(cake,n,visited,i,j+1);
        }
    }
    // check top
    if(i-1>=0){
        if(cake[i-1][j]==1&&visited[i-1][j]==0){
            ans+=dfs_run(cake,n,visited,i-1,j);
        }
    }
    // check bottom
    if(i+1<n){
        if(cake[i+1][j]==1&&visited[i+1][j]==0){
            ans+=dfs_run(cake,n,visited,i+1,j);
        }
    }
    // visited[i][j]=0;
    return 1+ans;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    int **visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[n]{};
    }
    int max_piece=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j]==1&&visited[i][j]==0){
                visited[i][j]=1;
                int ans=dfs_run(cake,n,visited,i,j);
                if(ans>max_piece){
                    max_piece=ans;
                }
            }
        }
    }
    return max_piece;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cake(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout<<getBiggestPieceSize(cake, n);
}
