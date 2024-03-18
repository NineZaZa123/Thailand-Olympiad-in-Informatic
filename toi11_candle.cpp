#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=2001;
int dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m,ans;
bool vis[N][N];
string s,mp[N];
queue<pii>q;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> s;
        mp[i]="x"+s;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(mp[i][j]=='0'||vis[i][j])continue;
            ans++;
            q.push({i,j});
            while(!q.empty()){
                int y=q.front().first;
                int x=q.front().second;
                q.pop();
                if(vis[y][x])continue;
                vis[y][x]=true;
                for(int k=0; k<8; k++){
                    int yy=y+dir[k][0];
                    int xx=x+dir[k][1];
                    if(yy<1||yy>n||xx<1||xx>m||mp[yy][xx]=='0'||vis[yy][xx])continue;
                    q.push({yy,xx});
                }
            }
        }
    }
    cout << ans;

    return 0;
}