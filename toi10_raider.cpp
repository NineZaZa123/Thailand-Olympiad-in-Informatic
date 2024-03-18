#include<bits/stdc++.h>
#define pii pair<int,pair<int,int>>
using namespace std;

const int N=105;
int dir1[6][2]={{-1,1},{0,1},{1,1},{1,0},{0,-1},{-1,0}},dir2[6][2]={{-1,0},{0,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int n,m;
int mp[N][N];
bool vis[N][N][1001];
queue<pii>q;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mp[i][j];
        }
    }
    if(mp[(n-1)/2-1][0]&&!(mp[(n-1)/2-1][0]%1))q.push({1,{(n-1)/2-1,0}});
    if(mp[(n-1)/2][0]&&!(mp[(n-1)/2][0]%1))q.push({1,{(n-1)/2,0}});
    if(mp[(n-1)/2+1][0]&&!(mp[(n-1)/2+1][0]%1))q.push({1,{(n-1)/2+1,0}});
    while(!q.empty()){
        int cnt=q.front().first;
        int y=q.front().second.first;
        int x=q.front().second.second;
        q.pop();
        if(y==(n-1)/2&&x==m-1){
            cout << cnt;
            return 0;
        }
        if(vis[y][x][cnt])continue;
        vis[y][x][cnt]=true;
        cnt++;
        if(!(y&1)){
            for(int i=0; i<6; i++){
                int yy=y+dir1[i][0];
                int xx=x+dir1[i][1];
                if(yy<0||yy>=n||xx<0||xx>=m||!mp[yy][xx]||cnt%mp[yy][xx]||vis[yy][xx][cnt])continue;
                q.push({cnt,{yy,xx}});
            }
        }
        else{
            for(int i=0; i<6; i++){
                int yy=y+dir2[i][0];
                int xx=x+dir2[i][1];
                if(yy<0||yy>=n||xx<0||xx>=m||!mp[yy][xx]||cnt%mp[yy][xx]||vis[yy][xx][cnt])continue;
                q.push({cnt,{yy,xx}});
            }
        }
    }

    return 0;
}