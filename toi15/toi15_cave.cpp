#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define piii pair<ll,pii>
using namespace std;

const int N=2001;
int n,s,e,m,q;
ll dis[N][N];
vector<pii>vec;
bitset<N>vis[N];
vector<pii>adj[N];
priority_queue<piii,vector<piii>,greater<piii>>pq;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> s >> e >> m;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dis[i][j]=LLONG_MAX;
        }
    }
    dis[s][0]=0;
    pq.push({0,{0,s}});
    while(!pq.empty()){
        int cnt=pq.top().second.first;
        int u=pq.top().second.second;
        pq.pop();
        if(vis[u][cnt])continue;
        vis[u][cnt]=true;
        if(u==e){
            vec.push_back({dis[u][cnt],cnt});
        }
        for(pii wv:adj[u]){
            ll w=wv.first;
            int v=wv.second;
            if(u==s||v==s){
                if(dis[u][cnt]+w<dis[v][cnt]){
                    dis[v][cnt]=dis[u][cnt]+w;
                    pq.push({dis[v][cnt],{cnt,v}});
                }
            }
            else{
                if(dis[u][cnt]+w<dis[v][cnt+1]){
                    dis[v][cnt+1]=dis[u][cnt]+w;
                    pq.push({dis[v][cnt+1],{cnt+1,v}});
                }
            }
        }
    }
    cin >> q;
    while(q--){
        ll h;
        cin >> h;
        ll ans=LLONG_MAX;
        for(pii i:vec){
            ans=min(ans,i.first+(h*i.second));
        }
        cout << ans << ' ';
    }

    return 0;
}