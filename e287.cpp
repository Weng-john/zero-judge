#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

bool boolMap[101][101];
int  n, m, Map[101][101];
int ans=0, dir[4][2]={{0,-1},{1,0},{0,1},{-1,0}};

bool canGo(int x,int y){
    if(x>=0 && y>=0 && x<n && y<m)
        return true;
    return false;
}

void DFS(pii p){
    int x= p.first;
    int y= p.second;
    boolMap[x][y]= true;
    ans += Map[x][y];
    int Min= INT_MAX;
    pii nextStep= {-1,-1};
    for(int i=0;i<4;i++){
        int tmpX= x+dir[i][0];
        int tmpY= y+dir[i][1];
        if(!(boolMap[tmpX][tmpY]) && canGo(tmpX, tmpY)){
            if(Map[tmpX][tmpY]<Min){
                nextStep= make_pair(tmpX, tmpY);
                Min= Map[tmpX][tmpY];
            }
        }
    }
    if(nextStep.first+1)
        DFS(nextStep);
    else
        return;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    pii startStep={-1,-1};
    int Min=INT_MAX;
    while(cin >> n >> m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> Map[i][j];
                if(Map[i][j]<=Min){
                    startStep= make_pair(i, j);
                    Min= Map[i][j];
                }
            }
        }
        DFS(startStep);
        cout << ans <<endl;
        return 0;
    }
}
