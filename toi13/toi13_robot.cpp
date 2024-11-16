#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N=2001;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
ll cnt,ans;
ll dp[N][N];
string mp[N];
vector<pii>pos;
queue<pii>q;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> mp[i];
        mp[i]="x"+mp[i];
        for(int j=1; j<=m; j++){
            dp[i][j]=LLONG_MAX;
            if(mp[i][j]=='A')pos.push_back({i,j});
            else if(mp[i][j]=='X'){
                q.push({i,j});
                dp[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int yy=y+dir[i][0];
            int xx=x+dir[i][1];
            if(yy<1||yy>n||xx<1||xx>m||dp[y][x]+1>=dp[yy][xx]||mp[yy][xx]=='W')continue;
            dp[yy][xx]=dp[y][x]+1;
            q.push({yy,xx});
        }
    }
    for(pii yx:pos){
        int y=yx.first;
        int x=yx.second;
        if(dp[y][x]<LLONG_MAX){
            ans+=dp[y][x]*2;
            cnt++;
        }
    }
    cout << cnt << ' ' << ans;

    return 0;
}