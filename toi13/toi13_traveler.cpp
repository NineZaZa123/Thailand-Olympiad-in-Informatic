#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;

const int N=1e4+1;
int n,m,x,y,z;
ll dis[N][2];
bool vis[N][2];
vector<pii>adj[N];
priority_queue<pii,vector<pii>,greater<pii>>pq;

void dijsktra(int k){
    if(!k)pq.push({0,x});
    else pq.push({0,y});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u][k])continue;
        vis[u][k]=true;
        for(pii wv:adj[u]){
            ll w=wv.first;
            int v=wv.second;
            if(dis[v][k]>dis[u][k]+w){
                dis[v][k]=dis[u][k]+w;
                pq.push({dis[v][k],v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> x >> y >> z;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for(int i=0; i<n; i++){
        if(i!=x)dis[i][0]=LLONG_MAX;
        if(i!=y)dis[i][1]=LLONG_MAX;
    }
    dijsktra(0);
    dijsktra(1);
    if(dis[y][0]<=z)cout << y << ' ' << dis[y][0] << ' ' << 0;
    else{
        ll ans,mn=LLONG_MAX;
        for(int i=0; i<n; i++){
            if(dis[i][0]<=z&&dis[i][1]<mn){
                ans=i;
                mn=dis[i][1];
            }
        }
        cout << ans << ' ' << dis[ans][0] << ' ' << dis[ans][1];
    }

    return 0;
}