#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
using namespace std;

const int N=2501;
int n;
int arr[N];
ll mx;
pii dp;
vector<int>ans;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        dp.second+=arr[i];
        if(!dp.first)dp.first=i;
        if(dp.second>mx){
            mx=dp.second;
            ans.clear();
            for(int j=dp.first; j<=i; j++){
                ans.push_back(arr[j]);
            }
        }
        else if(dp.second<=0){
            dp.first=0;
            dp.second=0;
        }
    }
    for(int i:ans)cout << i << ' ';
    if(mx)cout << '\n' << mx;
    else cout << "Empty sequence";

    return 0;
}