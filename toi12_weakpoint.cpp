#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1;
int n,m,k;
int node,mx=-1;
int compo[N],composz[N],dp[N];
bool vis[N],vis2[N],incir[N],chk;
vector<int>adj[N],cir;

void dfs(int u,int p){
    if(vis[u]){
        if(incir[u])return ;
        incir[u]=true;
        cir.push_back(u);
        chk=true;
        k=u;
        return ;
    }
    vis[u]=true;
    for(int v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        if(incir[v]&&chk&&!incir[u]){
            incir[u]=true;
            cir.push_back(u);
        }
    }
    if(u==k)chk=false;
}

void dfs2(int u,int p){
    if(vis2[u])return ;
    vis2[u]=true;
    for(int v:adj[u]){
        if(v==p||incir[v])continue;
        dfs2(v,u);
        dp[u]+=dp[v]+1;
    }
}

void dfs3(int u,int p){
    vis2[u]=true;
    for(int v:adj[u]){
        if(v==p||vis2[v]||v==m)continue;
        dfs3(v,u);
        dp[u]+=dp[v]+1;
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(m,-1);
    if(incir[m]){
        for(int i:cir){
            dfs2(i,-1);
        }
    }
    else{
        for(int i:adj[m]){
            dfs3(i,-1);
        }
    }
    for(int i=1; i<=n; i++){
        if(i==m)continue;
        if(dp[i]>mx){
            node=i;
            mx=dp[i];
        }
    }
    cout << node << '\n' << mx;

    return 0;
}

/*
10 1
1 2
2 4
1 3
1 5
5 6
6 7
7 8
8 9
9 10
8 5
*/