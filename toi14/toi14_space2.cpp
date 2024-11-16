#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=1e4+1,M=2001;
int dir[3][2]={{0,-1},{0,1},{1,0}};
int n,m;
int a,b,c;
bitset<M>mp[N+1],vis[N];
vector<pii>v;
queue<pii>q;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> m >> n;
    for(int j=0; j<=m+1; j++)mp[0][j]=0;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        s="0"+s;
        mp[i][0]=mp[i][m+1]=0;
        for(int j=1; j<=m; j++){
            mp[i][j]=s[j]-'0';
            if(mp[i][j]==1&&mp[i][j-1]!=1&&mp[i-1][j]!=1)v.push_back({i,j});
        }
    }
    mp[n+1]=mp[0];
    for(pii ij:v){
        int ii=ij.first;
        int jj=ij.second;
        int cnt=0;
        if(vis[ii][jj])continue;
        q.push({ii,jj});
        while(!q.empty()){
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            if(vis[y][x])continue;
            vis[y][x]=true;
            int tmp=0;
            if(mp[y+1][x]==0)tmp++;
            if(mp[y-1][x]==0)tmp++;
            if(mp[y][x+1]==0)tmp++;
            if(mp[y][x-1]==0)tmp++;
            if(tmp==3)cnt++;
            for(int i=0; i<3; i++){
                int yy=y+dir[i][0];
                int xx=x+dir[i][1];
                if(yy<1||yy>n||xx<1||xx>m||mp[yy][xx]==0)continue;
                q.push({yy,xx});
            }
        }
        if(cnt==0)a++;
        else if(cnt==4)b++;
        else c++;
    }
    cout << a << ' ' << b << ' ' << c;

    return 0;
}