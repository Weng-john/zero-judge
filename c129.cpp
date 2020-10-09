#include <bits/stdc++.h>

using namespace std;
char ground[105][105];
bool blGround[105][105];
int m, n, ans;

void DFS(int row, int col){
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(!blGround[row+i][col+j]){
                if(ground[row+i][col+j]=='@'){
                    blGround[row+i][col+j]=true;
                    DFS(row+i,col+j);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while((cin >> n >> m)&&((n!=0)&&(m!=0))){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ground[i][j]='*';
                blGround[i][j]=false;
            }
        }
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin >> ground[i+1][j+1];
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!blGround[i][j]){
                    blGround[i][j]=true;
                    if(ground[i][j]=='@'){
                        ans++;
                        DFS(i, j);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
