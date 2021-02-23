/*
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix.
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/


#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<char>> board,int n,int m,int i,int j,bool **visited,string s){
    if(s.length()==0){
        return 1;
    }
    if(i>=n || j>=m || i<0 || j<0 ){
        return 0;
    }
    int allSurroundRowElement[]={i-1,i,i+1};
    int allSurroundColumnElement[]={j-1,j,j+1};
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            int nexti=allSurroundRowElement[a];
            int nextj=allSurroundColumnElement[b];
            if((allSurroundRowElement[a]==i && allSurroundColumnElement[b]==j) || nexti>=n || nextj>=m || nexti<0 || nextj<0){ //next not going outside of matrix board
                continue;
            }
            if(board[nexti][nextj]==s[0] && !visited[nexti][nextj]){
                visited[nexti][nextj]=true;
                if(check(board,n,m,nexti,nextj,visited,s.substr(1))){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
    return false;

}
bool hasPath(vector<vector<char>> board,int n,int m){
    bool **visited=new bool*[n];
    for (int i = 0; i < n; ++i) {
        visited[i]=new bool[m];
        for (int j = 0; j < m; ++j) {
             visited[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='C'){
                string s="ODINGNINJA";
                if(check(board,n,m,i,j,visited,s)){
                    return 1;
                }
            }
            for(int k=0;k<n;k++){
                for(int l=0;l<m;k++){
                    visited[k][l]=false;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        delete []visited[i];
    }
    delete []visited;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}

/*int dfs_traversal(vector<vector<char>> &board,int n,int m,int curr_n,int curr_m,int **visited,int curr_el){
    if(curr_el>=11){
        return 1;
    }
    visited[curr_n][curr_m]=1;
    string cn="CODINGNINJA";
    int ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0,ans7=0,ans8=0;
    while(1){
        // cout<<1<<endl;
        // check top
        if(curr_n-1>=0){
            if(board[curr_n-1][curr_m]==cn[curr_el]&&visited[curr_n-1][curr_m]==0){
                // cout<<cn[curr_el]<<endl;
                ans1=dfs_traversal(board,n,m,curr_n-1,curr_m,visited,curr_el+1);
            }
        }
        if(ans1==1) break;
        // check bottom
        if(curr_n+1<n){
            if(board[curr_n+1][curr_m]==cn[curr_el]&&visited[curr_n+1][curr_m]==0){
                // cout<<cn[curr_el]<<endl;
                ans2=dfs_traversal(board,n,m,curr_n+1,curr_m,visited,curr_el+1);
            }
        }
        if(ans2==1) break;
        // check right
        if(curr_m+1<m){
            if(board[curr_n][curr_m+1]==cn[curr_el]&&visited[curr_n][curr_m+1]==0){
                // cout<<cn[curr_el]<<endl;
                ans3=dfs_traversal(board,n,m,curr_n,curr_m+1,visited,curr_el+1);
            }
        }
        if(ans3==1) break;
        // check left
        if(curr_m-1>=0){
            if(board[curr_n][curr_m-1]==cn[curr_el]&&visited[curr_n][curr_m-1]==0){
                // cout<<cn[curr_el]<<endl;
                ans4=dfs_traversal(board,n,m,curr_n,curr_m-1,visited,curr_el+1);
            }
        }
        if(ans4==1) break;
        // check diagonals
        // top right
        if(curr_m+1<m&&curr_n-1>=0){
            if(board[curr_n-1][curr_m+1]==cn[curr_el]&&visited[curr_n-1][curr_m+1]==0){
                // cout<<cn[curr_el]<<endl;
                ans5=dfs_traversal(board,n,m,curr_n-1,curr_m+1,visited,curr_el+1);
            }
        }
        if(ans5==1) break;
        // top left
        if(curr_m-1>=0&&curr_n-1>=0){
            if(board[curr_n-1][curr_m-1]==cn[curr_el]&&visited[curr_n-1][curr_m-1]==0){
                // cout<<cn[curr_el]<<endl;
                ans6=dfs_traversal(board,n,m,curr_n-1,curr_m-1,visited,curr_el+1);
            }
        }
        if(ans6==1) break;
        // bottom right
        if(curr_m+1<m&&curr_n+1<n){
            if(board[curr_n+1][curr_m+1]==cn[curr_el]&&visited[curr_n+1][curr_m+1]==0){
                // cout<<cn[curr_el]<<endl;
                ans7=dfs_traversal(board,n,m,curr_n+1,curr_m+1,visited,curr_el+1);
            }
        }
        if(ans7==1) break;
        // bottom left
        if(curr_m-1>=0&&curr_n+1<n){
            if(board[curr_n+1][curr_m-1]==cn[curr_el]&&visited[curr_n+1][curr_m-1]==0){
                // cout<<cn[curr_el]<<endl;
                ans8=dfs_traversal(board,n,m,curr_n+1,curr_m-1,visited,curr_el+1);
            }
        }
        // if(ans8==1) break;
        break;
    }
    visited[curr_n][curr_m]=0;
    if(ans1==1||ans2==1||ans3==1||ans4==1||ans5==1||ans6==1||ans7==1||ans8==1){
        return 1;
    }
    return 0;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    int **visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[m]{};
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='C'){
                visited[i][j]=1;
                int ans=dfs_traversal(board,n,m,i,j,visited,1);
                if(ans==1){
                    return 1;
                }
                visited[i][j]=0;
            }
            // for(int x=0;x<n;x++){
            //     for(int y=0;y<m;y++){
            //         visited[x][y]=0;
            //     }
            // }
        }
    }
    return 0;
}*/
