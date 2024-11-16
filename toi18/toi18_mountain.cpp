#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define piii pair<ll,pair<ll,ll>>
using namespace std;

const int N=501;
int n,m;
ll ans;
ll dis[N][N],dp[N][N],arr2[N];
pii pos[N],arr[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> pos[i].first >> pos[i].second;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]=LLONG_MAX;
            if(i==j)continue;
            ll x1=pos[i].first,y1=pos[i].second;
            ll x2=pos[j].first,y2=pos[j].second;
            dis[i][j]=abs(x1-x2)+abs(y1-y2);
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j||(k==1&&i==1))continue;
                if(k>1)dp[i][k]=min(dp[i][k],max(dis[i][j],dp[j][k-1]));
                else dp[i][k]=min(dp[i][k],dis[i][1]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        arr[i]={dp[n][i],i};
    }
    sort(arr+1,arr+n+1);
    for(int i=2; i<=n; i++){
        arr[i].second=min(arr[i-1].second,arr[i].second);
        arr2[i]=arr[i].first;
    }
    while(m--){
        ll w;
        cin >> w;
        int idx=upper_bound(arr2+1,arr2+n+1,w)-arr2-1;
        ans+=arr[idx].second;
    }
    cout << ans;

    return 0;
}