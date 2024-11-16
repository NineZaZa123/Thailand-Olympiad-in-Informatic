#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

const int N=5e5+1;
int n,m;
int mxval,mxnode=N;
int dp[N],pa;
bool chkcy,gotcy;
bitset<N>vis,isincy;
vector<int>adj[N];

void dfs(int u,int p){
    if(vis[u]){
        isincy[u]=true;
        chkcy=true;
        gotcy=true;
        return;
    }
    vis[u]=true;
    for(int v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        if(isincy[u])chkcy=false;
        if(isincy[v]&&chkcy){
            isincy[u]=true;
            return;
        }
        if(gotcy)return;
    }
}

void dfs2(int u,int p){
    if(u==m)pa=p;
    dp[u]=1;
    for(int v:adj[u]){
        if(v==p||isincy[v])continue;
        dfs2(v,u);
        dp[u]+=dp[v];
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
    dfs(m,0);
    for(int i=1; i<=n; i++){
        if(!isincy[i])continue;
        dfs2(i,0);
        if(isincy[m]){
            if(i!=m&&dp[i]-1>mxval){
                mxnode=i;
                mxval=dp[i]-1;
            }
            else if(i!=m&&dp[i]-1==mxval){
                mxnode=min(mxnode,i);
            }
        }
    }
    if(isincy[m]){
        for(int v:adj[m]){
            if(dp[v]-1>mxval){
                mxnode=v;
                mxval=dp[v]-1;
            }
            else if(dp[v]-1==mxval) mxnode=min(mxnode,v);
        }
    }
    else{
        for(int v:adj[m]){
            if(v==pa)continue;
            if(dp[v]-1>mxval){
                mxval=dp[v]-1;
                mxnode=v;
            }
            else if(dp[v]-1==mxval)mxnode=min(mxnode,v);
        }
        if(n-dp[m]-1>mxval){
            mxval=n-dp[m]-1;
            mxnode=pa;
        }
        else if(n-dp[m]-1==mxval)mxnode=min(mxnode,pa);
    }
    cout << mxnode << '\n' << mxval;

    return 0;
}