#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+1;
int n,m,k;
ll arr[N];

bool chk(ll w){
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    ll sum=0,cnt=0;
    for(int i=1; i<=n; i++){
        sum+=arr[i];
        pq.push(arr[i]);
        if(pq.size()>k){
            sum-=pq.top();
            pq.pop();
        }
        if(pq.size()==k&&sum>=w){
            if(cnt>=m)return true;
            sum=0;
            cnt++;
            while(!pq.empty())pq.pop();
        }
    }
    return (cnt>=m);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    ll l=1,r=1e16;
    while(l<r){
        ll mid=(l+r)/2;
        if(chk(mid))l=mid+1;
        else r=mid;
    }
    cout << l-1;

    return 0;
}

/*
12 3 3
1
2
3
4
5
6
7
8
9
10
12
13
*/