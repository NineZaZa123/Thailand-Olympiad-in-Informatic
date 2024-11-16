#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1;
int n,m,q,l;
int cannon[N],supply[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> q >> l;
    for(int i=1; i<=n; i++){
        cin >> cannon[i];
    }
    while(q--){
        for(int i=1; i<=m; i++){
            cin >> supply[i];
        }
        int idx=1;
        for(int i=1; i<=m; i++){
            int lw=lower_bound(cannon+idx,cannon+n,supply[i]-l)-cannon;
            if(cannon[lw]>supply[i]+l)continue;
            int up=upper_bound(cannon+idx,cannon+n,supply[i]+l)-cannon;
        }
    }

    return 0;
}