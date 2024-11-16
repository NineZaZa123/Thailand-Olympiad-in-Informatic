#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+1;
int n,m,q;
ll x[N],y[N],s[N],t[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++)cin >> x[i];
    for(int i=1; i<=n; i++){
        cin >> s[i];
        s[i]+=s[i-1];
    }
    for(int i=1; i<=m; i++)cin >> y[i];
    for(int i=1; i<=m; i++){
        cin >> t[i];
        t[i]+=t[i-1];
    }
    while(q--){
        ll a,b,k;
        cin >> a >> b >> k;
        ll l=-1e9,r=1e9;
        while(l<r){
            ll mid=(l+r)>>1;
            ll xx=s[upper_bound(x+1,x+n+1,mid)-x-1];
            ll yy=t[upper_bound(y+1,y+m+1,(mid-b)/a)-y-1];
            if(xx+yy<k)l=mid+1;
            else r=mid;
        }
        cout << l << '\n';
    }

    return 0;
}