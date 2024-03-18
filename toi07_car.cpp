#include<bits/stdc++.h>
using namespace std;

const int N=101;
int dir[4][2]={{0,0},{1,-1},{1,1},{1,0}};
int n,m,k;
int mp[N][N];
bool chk=true;
stack<int>s;

void dfs(int y,int x){
    if(y==n){
        chk=false;
        return ;
    }
    for(int i=1; i<=3; i++){
        int yy=y+dir[i][0];
        int xx=x+dir[i][1];
        if(mp[yy][xx]||xx<1||xx>m)continue;
        dfs(yy,xx);
        if(!chk){
            s.push(i);
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> m >> k >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mp[i][j];
        }
    }
    dfs(0,k);
    while(!s.empty()){
        cout << s.top() << '\n';
        s.pop();
    }

    return 0;
}
