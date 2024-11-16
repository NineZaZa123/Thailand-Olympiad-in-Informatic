#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1;
int n;
int arr[N];
vector<int>dp;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        auto it=upper_bound(dp.begin(),dp.end(),arr[i]);
        if(it==dp.end())dp.push_back(arr[i]);
        else *it=arr[i];
    }
    cout << n-dp.size();

    return 0;
}