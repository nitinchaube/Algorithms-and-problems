#include<iostream>
using namespace std;

#include<bits/stdc++.h>
void print(int **solution,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
}

void helpMaze(int maze[][20],int n,int** solution,int x,int y){

    if(x==n-1 && y==n-1){
        solution[x][y]=1;
        print(solution,n);
        return;
    }
    if(x>=n || x<0 ||y>=n || y<0|| solution[x][y]==1 || maze[x][y]==0){
        return;
    }
    solution[x][y]=1;
    helpMaze(maze,n,solution,x+1,y);
    helpMaze(maze,n,solution,x-1,y);
    helpMaze(maze,n,solution,x,y-1);
    helpMaze(maze,n,solution,x,y+1);
    solution[x][y]=0;
}
void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question

  */
    int** solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n];
    }
    helpMaze(maze,n,solution,0,0);


}

int main(){

  int n;
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }
  }
  ratInAMaze(maze, n);
}
