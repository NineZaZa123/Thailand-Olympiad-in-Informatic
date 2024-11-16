#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;

int n,s;
ll dis[(1<<20)];
bitset<(1<<20)>vis;
vector<int>apple;
vector<pii>adj[(1<<20)];
priority_queue<pii,vector<pii>,greater<pii>>pq;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> s;
    for(int i=1; i<=n; i++){
        ll w;
        cin >> w;
        int med=0,poi=0;
        for(int j=0; j<s; j++){
            int x;
            cin >> x;
            if(x==-1)poi|=(1<<j);
            else if(x==1) med|=(1<<j);
        }
        adj[poi].push_back({w,med});
        apple.push_back(poi);
    }
    for(int i=1; i<(1<<(s+1)); i++)dis[i]=INT_MAX;
    pq.push({0,0});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(pii wv:adj[u]){
            ll w=wv.first;
            int v=wv.second;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
        for(int i=0; i<s; i++){
            if(u&(1<<i)&&dis[u]<dis[u^(1<<i)]){
                dis[u^(1<<i)]=dis[u];
                pq.push({dis[u],u^(1<<i)});
            }
        }
    }
    ll ans=0;
    for(int i:apple){
        if(dis[i]<INT_MAX)ans=max(ans,dis[i]);
    }
    cout << ans;

    return 0;
}