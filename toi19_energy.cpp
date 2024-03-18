#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=301,MOD=1e9+7;
ll n,k,d;
ll arr[N];
ll qs[N],dp[N][N][10];

ll solve(int l,int r,int lv){
    if(lv==k)return 1;
    if(dp[l][r][lv]!=-1)return dp[l][r][lv];
    ll ans=0;
    for(int i=l; i<r; i++){
        if(abs((qs[i]-qs[l-1])-(qs[r]-qs[i]))>d)continue;
        ans+=((solve(l,i,lv+1)%MOD)*(solve(i+1,r,lv+1)%MOD))%MOD;
        ans%=MOD;
    }
    return dp[l][r][lv]=ans;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k >> d;
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        qs[i]=qs[i-1]+arr[i];
    }
    cout << solve(1,n,1);

    return 0;
}