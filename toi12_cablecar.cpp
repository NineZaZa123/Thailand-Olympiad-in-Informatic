#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=2501;
int n,m,s,e,p;
int dis[N];
bool vis[N];
vector<pii>adj[N];
priority_queue<pii>pq;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cin >> s >> e >> p;
    pq.push({INT_MAX,s});
    dis[s]=INT_MAX;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(pii wv:adj[u]){
            int w=min(wv.first,dis[u]);
            int v=wv.second;
            if(w>dis[v]){
                dis[v]=w;
                pq.push({dis[v],v});
            }
        }
    }
    cout << (p/(dis[e]-1))+(p%(dis[e]-1)!=0);

    return 0;
}