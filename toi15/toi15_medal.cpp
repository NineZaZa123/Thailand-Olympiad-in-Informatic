#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+1;
int n;
ll t[N],h[N];

bool comp(ll a,ll b){
    return b<a;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)cin >> t[i];
    for(int i=1; i<=n; i++)cin >> h[i];
    sort(t+1,t+n+1,comp);
    sort(h+1,h+n+1);
    ll mn=LLONG_MAX,mx=0;
    for(int i=1; i<=n; i++){
        mx=max(mx,t[i]+h[i]);
        mn=min(mn,t[i]+h[i]);
    }
    cout << mx-mn;

    return 0;
}