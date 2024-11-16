#include<bits/stdc++.h>
#define pii pair<int,pair<int,int>>
using namespace std;

const int N=4e5+1;
int n;
int lis[N];
pii arr[N];
vector<int>dp;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        arr[i].first=i;
        cin >> arr[i].second.first >> arr[i].second.second;
    }
    sort(arr+1,arr+n+1,[&](pii a,pii b){
        if(a.second.second!=b.second.second)return a.second.second<b.second.second;
        else return a.second.first>b.second.first;
    });
    for(int i=1; i<=n; i++){
        auto it=upper_bound(dp.begin(),dp.end(),-arr[i].second.first);
        if(dp.empty()||it==dp.end()){
            dp.push_back(-arr[i].second.first);
            lis[arr[i].first]=dp.size();
        }
        else{
            *it=-arr[i].second.first;
            lis[arr[i].first]=it-dp.begin()+1;
        }
    }
    cout << dp.size() << '\n';
    for(int i=1; i<=n; i++)cout << lis[i] << ' ';

    return 0;
}