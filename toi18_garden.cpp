#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+1;
int n,q;
ll arr[N];
int lis[N],ans[N];
vector<int>dp1,dp2;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cin.tie(0);
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        auto it=lower_bound(dp1.begin(),dp1.end(),arr[i]);
        lis[i]=it-dp1.begin();
        if(it==dp1.end())dp1.push_back(arr[i]);
        else *it=arr[i];
    }
    for(int i=n-1; i>=0; i--){
        auto it=lower_bound(dp2.begin(),dp2.end(),arr[i]);
        ans[i]=min(lis[i],int(it-dp2.begin()));
        if(it==dp2.end())dp2.push_back(arr[i]);
        else *it=arr[i];
    }
    while(q--){
        int idx;
        cin >> idx;
        cout << ans[idx] << '\n';
    }

    return 0;
}