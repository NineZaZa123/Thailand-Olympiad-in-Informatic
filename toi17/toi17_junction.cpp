#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;

const int N=8e4+1;
int n;
int st;
vector<pii>adj[N];
vector<ll>vec;

void dfs(int u,int p){
    for(pii wv:adj[u]){
        ll w=wv.first;
        int v=wv.second;
        if(v==p)continue;
        dfs(v,u);
        vec.push_back(w);
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for(int i=0; i<=n; i++){
        if(adj[i].size()==1){
            st=i;
            break;
        }
    }
    dfs(st,-1);
    ll l=0,r=1e10;
    while(l<r){
        int mid=(l+r+1)>>1;
        ll sum=0,cnt=0;
        for(ll w:vec){
            sum+=w;
            if(sum>=mid){
                sum=0;
                cnt++;
            }
        }
        if(cnt>=3)l=mid;
        else r=mid-1;
    }
    cout << l;

    return 0;
}