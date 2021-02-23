/*
Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board.
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.
Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true
*/


#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>&board,int n,int m,int i,int j,bool **visited,char current){
//BASE CASES
    int count;
    //top element of current one
    if(i-1>=0){
        if(visited[i-1][j]){
            count++;
        }
    }
    //down element of current one
    if(i+1<n){
        if(visited[i+1][j]){
            count++;
        }
    }
    //left element of current one
    if(j-1>=0){
        if(visited[i][j-1]){
            count++;
        }
    }
    //right element of current one
    if(j+1<n){
        if(visited[i][j+1]){
            count++;
        }
    }
    if(count>=2){
        return 1;
    }

//Base  cases ends
    int ans=0;
    while(1){
        //top element is current
        if(i-1 >=0){
            if(board[i-1][j]==current && !visited[i-1][j]){
                ans=dfs(board,m,n,i-1,j,visited,current);
            }
        }
        if(ans){
            break;
        }
        //dowm element is curent
        if(i+1 <n){
            if(board[i+1][j]==current && !visited[i+1][j]){
                ans=dfs(board,m,n,i+1,j,visited,current);
            }
        }
        if(ans){
            break;
        }
        //left element is current
        if(j-1>=0){
            if(board[i][j-1]==current && !visited[i][j-1]){
                ans=dfs(board,m,n,i,j-1,visited,current);
            }
        }
        if(ans){
            break;
        }
        //right element is current
        if(j+1 <n){
            if(board[i][j+1]==current && !visited[i][j+1]){
                ans=dfs(board,m,n,i,j+1,visited,current);
            }
        }
        if(ans){
            break;
        }

        break;
    }
    visited[i][j]=true;
    return ans;



}

bool hasCycle(vector<vector<char>> &board,int n,int m){
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char current=board[i][j];
            bool result=dfs(board,m,n,i,j,visited,current);
            if(result){
                return true;
            }
        }
    }
    return false;
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}
















