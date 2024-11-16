#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define piii pair<ll,pii>
using namespace std;

const int N=3001;
int n,m,q;
ll ans;
int pa[N];
vector<pii>adj[N];
priority_queue<piii,vector<piii>,greater<piii>>pq;

int root(int x){
    if(x==pa[x])return x;
    else return pa[x]=root(pa[x]);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++)pa[i]=i;
    for(int i=1; i<=m; i++){
        ll u,v,w,r;
        cin >> u >> v >> w >> r;
        if(r){
            pa[root(u)]=root(v);
            continue;
        }
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
        pq.push({w,{u,v}});
    }
    cin >> q;
    pii arr[q+1];
    for(int i=1; i<=q; i++)cin >> arr[i].first >> arr[i].second;
    while(!pq.empty()){
        ll w=pq.top().first;
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        pq.pop();
        if(root(u)==root(v))continue;
        pa[root(u)]=root(v);
        ll p=LLONG_MAX;
        for(int i=1; i<=q; i++){
            if(arr[i].first>=w)p=min(p,arr[i].second);
        }
        ans+=p;
    }
    cout << ans;

    return 0;
}