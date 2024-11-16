#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int MOD=1e9+7;
int t,q,n;
int ans;
vector<ll>dataset;
vector<pii>vec;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t >> q;
    while(t--){
        cin >> n;
        for(int i=1; i<n; i++){
            int u,v;
            cin >> u >> v;
            vec.push_back({min(u,v),max(u,v)});
        }
        sort(vec.begin(),vec.end());
        ll hsh=0;
        for(int i=0; i<n-1; i++){
            hsh*=4;
            hsh+=((vec[i].first*2)+vec[i].second);
            hsh%=MOD;
        }
        vec.clear();
        dataset.push_back(hsh);
    }
    while(q--){
        ans=0;
        cin >> n;
        for(int i=1; i<n; i++){
            int u,v;
            cin >> u >> v;
            vec.push_back({min(u,v),max(u,v)});
        }
        sort(vec.begin(),vec.end());
        ll hsh=0;
        for(int i=0; i<n-1; i++){
            hsh*=4;
            hsh+=((vec[i].first*2)+vec[i].second);
            hsh%=MOD;
        }
        for(ll i:dataset){
            if(hsh==i)ans++;
        }
        vec.clear();
        cout << ans << '\n';
    }

    return 0;
}