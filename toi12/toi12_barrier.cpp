#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;

const int N=6e6+1;
int n,w;
ll sum,ans;
int cnt;
deque<pii>dq;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> w;
    dq.push_back({0,0});
    for(int i=1; i<=n; i++){
        ll x;
        cin >> x;
        sum+=x;
        while(!dq.empty()&&dq.back().first>=sum){
            dq.pop_back();
        }
        dq.push_back({sum,i});
        while(!dq.empty()&&dq.front().second<i-w){
            dq.pop_front();
        }
        ll v=dq.front().first;
        int idx=dq.front().second;
        if(sum-v>ans){
            cnt=i-idx;
            ans=sum-v;
        }
        else if(sum-v==ans) cnt=min(cnt,i-idx);
    }
    cout << ans << '\n' << cnt;

    return 0;
}