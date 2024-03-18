#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;

const int N=1e5+1;
int n,q;
ll arr[N];
pii dp[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        arr[i]+=arr[i-1];
        dp[i]={arr[i],i};
    }
    sort(dp+1,dp+n+1,[&](pii a,pii b){
        if(a.first!=b.first)return a.first<b.first;
        else return a.second>b.second;
    });
    for(int i=1; i<=n; i++){
        arr[i]=dp[i].first;
        dp[i].second=max(dp[i].second,dp[i-1].second);
    }
    while(q--){
        ll tmp;
        cin >> tmp;
        int idx=upper_bound(arr+1,arr+n+1,tmp)-arr-1;
        cout << dp[idx].second << '\n';
    }

    return 0;
}