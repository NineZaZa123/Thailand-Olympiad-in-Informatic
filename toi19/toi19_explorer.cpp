#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+1,MOD=1e9+7;
int n;
int arr[2*N];
ll fac[N],dp[N];
vector<int>adj[N];

void dfs(int u,int p){
    dp[u]=1;
    int cnt=0;
    for(int v:adj[u]){
        if(v==p)continue;
        dfs(v,u);
        cnt++;
        dp[u]*=dp[v];
        dp[u]%=MOD;
    }
    dp[u]*=fac[cnt];
    dp[u]%=MOD;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    fac[0]=1;
    for(int i=1; i<=n; i++){
        fac[i]=(fac[i-1]*i)%MOD;
    }
    for(int i=1; i<2*n; i++){
        cin >> arr[i];
        if(i>1)adj[arr[i-1]].push_back(arr[i]);
    }
    dfs(arr[1],0);
    cout << dp[arr[1]];

    return 0;
}