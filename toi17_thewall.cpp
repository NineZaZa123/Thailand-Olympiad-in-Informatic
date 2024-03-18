#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=1001;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int ans,cnt;
bool vis[N][N],vis2[N][N];
string s,mp[N];
vector<pii>v;
queue<pii>q;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> s;
        mp[i]="."+s;
        for(int j=1; j<=m; j++){
            if(mp[i][j]=='X')v.push_back({i,j});
        }
    }
    q.push({1,1});
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        if(vis[y][x])continue;
        vis[y][x]=true;
        for(int i=0; i<4; i++){
            int yy=y+dir[i][0];
            int xx=x+dir[i][1];
            if(yy<1||xx<1||yy>n||xx>m||mp[yy][xx]=='X')continue;
            q.push({yy,xx});
        }
    }
    for(pii ij:v){
        int i=ij.first;
        int j=ij.second;
        if(vis2[i][j])continue;
        cnt=0;
        q.push({i,j});
        while(!q.empty()){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            if(vis2[y][x])continue;
            vis2[y][x]=true;
            for(int i=0; i<4; i++){
                int yy=y+dir[i][0];
                int xx=x+dir[i][1];
                if(yy<1||yy>n||xx<1||xx>m)continue;
                if(mp[yy][xx]=='.'){
                    if(vis[yy][xx])cnt++;
                    continue;
                }
                q.push({yy,xx});
            }
        }
        ans=max(ans,cnt);
    }
    cout << ans;

    return 0;
}

/*
4 6
......
.X.X..
.X.XX.
......

5 5
.....
..X..
.X.X.
..X..
.....
*/