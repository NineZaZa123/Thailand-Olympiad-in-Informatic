#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define piii pair<pii,pii>
using namespace std;

const int MOD=5e6+11;
ll n,tx,ty;
int mx;
piii hs[MOD];
vector<pii>v1,v2,v3,v4;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> tx >> ty >> n;
    for(int i=0; i<MOD; i++)hs[i]={{LLONG_MAX,LLONG_MAX},{LLONG_MAX,LLONG_MAX}};
    for(int i=1; i<=n; i++){
        ll x,y;
        cin >> x >> y;
        v1.push_back({x,y});
    }
    for(int i=1; i<=n; i++){
        ll x,y;
        cin >> x >> y;
        v2.push_back({x,y});
    }
    for(pii xy1:v1){
        for(pii xy2:v2){
            ll x1=xy1.first,y1=xy1.second;
            ll x2=xy2.first,y2=xy2.second;
            ll xx=x1+x2,yy=y1+y2;
            ll idx=(((xx+yy)*3)%MOD+MOD)%MOD;
            int cnt=0;
            while(1){
                if(hs[idx].first.first==LLONG_MAX){
                    hs[idx]={{x1,y1},{x2,y2}};
                    break;
                }
                idx++;
                idx%=MOD;
                cnt++;
                mx=max(mx,cnt);
            }
        }
    }
    for(int i=1; i<=n; i++){
        ll x,y;
        cin >> x >> y;
        v3.push_back({x,y});
    }
    for(int i=1; i<=n; i++){
        ll x,y;
        cin >> x >> y;
        v4.push_back({x,y});
    }
    for(pii xy3:v3){
        for(pii xy4:v4){
            ll x3=xy3.first,y3=xy3.second;
            ll x4=xy4.first,y4=xy4.second;
            ll xx=tx-(x3+x4),yy=ty-(y3+y4);
            ll idx=(((xx+yy)*3)%MOD+MOD)%MOD;
            for(int i=0; i<=mx; i++,idx++){
                idx%=MOD;
                if(hs[idx].first.first+hs[idx].second.first+x3+x4==tx&&hs[idx].first.second+hs[idx].second.second+y3+y4==ty){
                    cout << hs[idx].first.first << ' ' << hs[idx].first.second << '\n';
                    cout << hs[idx].second.first << ' ' << hs[idx].second.second << '\n';
                    cout << x3 << ' ' << y3 << '\n';
                    cout << x4 << ' ' << y4;
                    return 0;
                }
            }
        }
    }

    return 0;
}
