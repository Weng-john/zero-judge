#include <bits/stdc++.h>

using namespace std;

bool blCity[100005];
vector  <int64_t> city[100005];

void DFS(int64_t current){
    if(!blCity[current]){
        blCity[current]=true;
        for(int64_t i=0;i<city[current].size();i++)
            DFS(city[current][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int64_t n, m, targetA, targetB;
    while(cin >> n >> m){
        memset(blCity,0,sizeof(blCity));
        for (int64_t i=0;i<=n;i++)
            city[i].clear();

        for(int64_t i=0;i<(m);i++){
            int64_t tmpA, tmpB;
            cin >> tmpA >> tmpB;
            city[tmpA].push_back(tmpB);
        }
        cin >> targetA >> targetB;

        for(int64_t i=0;i<city[targetA].size();i++)
            DFS(city[targetA][i]);
        if(blCity[targetB])
            cout << "Yes!!!" << endl;
        else
            cout << "No!!!" << endl;
    }
    return 0;
}
