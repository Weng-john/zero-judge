#include <bits/stdc++.h>

using namespace std;

char Map[10000][10000];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

void DFS(int x, int y){
    if(Map[x][y]=='-'){
        Map[x][y]='+';
        for(int i=0;i<4;i++)
            DFS(x+dir[i][0],y+dir[i][1]);
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, targetX, targetY;
    while(cin >> n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin >> Map[i+1][j+1];
        }
        cin >> targetX >> targetY;

        DFS(targetX+1, targetY+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << Map[i+1][j+1];
            cout << "\n";
        }
    }
    return 0;
}
