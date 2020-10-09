#include <bits/stdc++.h>

using namespace std;

vector <int64_t> num;
vector <int64_t> Resuit;
int64_t n,m;

void DFS(int64_t index){
    Resuit.push_back(num[index]);
    if(Resuit.size()<m){
        for(int64_t i=(index+1);i<n;i++)
            DFS(i);
    }
    if (Resuit.size()==m){
        for(int64_t i=0;i<m;i++){
            cout << Resuit[i] << " ";
        }
        cout << "\n";
    }
    Resuit.pop_back();
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while(cin >> n&&n){
            num.clear();
            Resuit.clear();
            for(int64_t i=0;i<n;i++){
                int64_t tmp;
                cin >> tmp;
                num.push_back(tmp);
            }
            cin >> m;
            sort(num.begin(),num.end());

            for(int64_t i=0;i<num.size();i++)
                DFS(i);
            cout << "\n";

    }
    return 0;
}
