#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=1e5+1;
int n,k,t;
int cnt,ans=-1;
short vis[N];
vector<int>adj[N],level[N];

void dfs(int u){
    if(vis[u]==2||cnt>t)return ;
    if(vis[u]==1){
        cnt=1e9;
        return ;
    }
    vis[u]=1;
    cnt++;
    for(int v:adj[u]){
        dfs(v);
    }
    vis[u]=2;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k >> t;
    for(int i=1; i<=n; i++){
        int l,p;
        cin >> l >> p;
        level[l].push_back(i);
        for(int j=1; j<=p; j++){
            int u;
            cin >> u;
            adj[i].push_back(u);
        }
    }
    for(int i=1; i<=k; i++){
        for(int u:level[i]){
            if(!vis[u])dfs(u);
        }
        if(cnt<=t)ans=i;
        else break;
    }
    cout << ans;

    return 0;
}