#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5001;
int n;
ll arr[N];
ll cutdp[N],eatdp[N][N];

ll eat(int l,int r){
    if(l==r)return arr[l];
    if(eatdp[l][r])return eatdp[l][r];
    return eatdp[l][r]=max(eat(l+1,r)+arr[l],eat(l,r-1)+arr[r])+abs(arr[l]-arr[r]);
}

ll cut(int l){
    if(l==n)return 0;
    if(cutdp[l])return cutdp[l];
    ll ans=-1;
    for(int i=l; i<=n; i++){
        ans=max(ans,eat(l,i)+cut(i+1));
    }
    return cutdp[l]=ans;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    cout << cut(1)+1;

    return 0;
}