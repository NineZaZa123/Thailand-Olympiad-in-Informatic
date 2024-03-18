#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define piii pair<int,pair<int,int>>
using namespace std;

const int N=2e4+1;
int n,m,k,p;
int arr[N];
int pa[N],pacnt[N];
ll dis[N];
bool vis[N];
set<int>st[N],adj2[N];
vector<pii>adj[N],ans;
queue<int>q;
priority_queue<pii,vector<pii>,greater<pii>>pq;

void dfs(int u){
    if(pa[u]==-1)return;
    st[pa[u]].insert(u);
    adj2[u].insert(pa[u]);
    dfs(pa[u]);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k >> p;
    for(int i=1; i<=k; i++)cin >> arr[i];
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for(int i=0; i<n; i++){
        if(i!=p)dis[i]=LLONG_MAX;
        pa[i]=-1;
    }
    pq.push({0,p});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0; i<adj[u].size(); i++){
            int v=adj[u][i].second;
            ll w=adj[u][i].first;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pa[v]=u;
                pq.push({dis[v],v});
            }
        }
    }
    for(int i=1; i<=k; i++){
        cout << dis[arr[i]] << ' ';
        dfs(arr[i]);
    }
    cout << '\n';
    for(int i=0; i<n; i++)pacnt[i]=st[i].size();
    for(int i=1; i<=k; i++){
        if(!pacnt[arr[i]])q.push(arr[i]);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj2[u]){
            ans.push_back({min(u,v),max(u,v)});
            pacnt[v]--;
            if(!pacnt[v])q.push(v);
        }
    }
    cout << ans.size() << '\n';
    for(pii i:ans){
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}