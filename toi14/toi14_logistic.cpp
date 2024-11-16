#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define piii pair<pii,pii>
using namespace std;

const int N=101;
int n,m,st,ed,f;
ll p[N],dis[N][N][2];
bool vis[N][N][2];
vector<pii>adj[N];
priority_queue<piii,vector<piii>,greater<piii>>pq;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    cin >> st >> ed >> f >> m;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=f; j++){
            dis[i][j][0]=dis[i][j][1]=LLONG_MAX;
        }
    }
    dis[st][0][1]=0;
    pq.push({{0,1},{0,st}});
    int cnt=0;
    while(!pq.empty()){
        int pass=pq.top().first.second;
        int fuel=pq.top().second.first;
        int u=pq.top().second.second;
        pq.pop();
        if(vis[u][fuel][pass])continue;
        vis[u][fuel][pass]=true;
        for(pii wv:adj[u]){
            int w=wv.first;
            int v=wv.second;
            int price=0,fl=fuel;
            if(fuel<w){
                fl=w;
                price=(w-fuel)*p[u];
            }
            if(pass&&dis[u][fuel][pass]<dis[v][f-w][0]){
                dis[v][f-w][0]=dis[u][fuel][pass];
                pq.push({{dis[v][f-w][0],0},{f-w,v}});
            }
            for(int i=fl; i<=f; i++,price+=p[u]){
                if(dis[u][fuel][pass]+price<dis[v][i-w][pass]){
                    dis[v][i-w][pass]=dis[u][fuel][pass]+price;
                    pq.push({{dis[v][i-w][pass],pass},{i-w,v}});
                }
            }
        }
    }
    ll ans=LLONG_MAX;
    for(int i=0; i<=f; i++){
        if(dis[ed][i][0]!=LLONG_MAX)ans=min(ans,dis[ed][i][0]+((f-i)*p[ed]));
        ans=min(ans,dis[ed][i][1]);
    }
    cout << ans;

    return 0;
}