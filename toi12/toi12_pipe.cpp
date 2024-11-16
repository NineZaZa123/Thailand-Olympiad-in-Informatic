#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

const int N=2e4+1;
int n,k;
ll ans;
ll dis[N];
pii pos[N];
bool vis[N];
queue<int>q;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        dis[i]=LLONG_MAX;
        cin >> pos[i].first >> pos[i].second;
    }
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        ans+=dis[u];
        int v;
        ll mndis=LLONG_MAX;
        for(int i=1; i<=n; i++){
            if(vis[i])continue;
            dis[i]=min(dis[i],abs(pos[u].first-pos[i].first)+abs(pos[u].second-pos[i].second));
            if(dis[i]<mndis){
                v=i;
                mndis=dis[i];
            }
        }
        q.push(v);
    }
    sort(dis+1,dis+n+1);
    for(int i=n; i>n-k; i--){
        ans-=dis[i];
    }
    cout << ans;

    return 0;
}