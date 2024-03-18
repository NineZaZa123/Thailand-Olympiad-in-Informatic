#include<bits/stdc++.h>
using namespace std;

const int N=1001;
int n;
int dp[N][N];
char arr[N];

int solve(int l,int r){
    if(l>=r)return dp[l][r]=0;
    if(dp[l][r]!=-1)return dp[l][r];
    if(arr[l]==arr[r]&&l+1==r)return dp[l][r]=1;
    if(l+1==r)return dp[l][r]=0;
    if(arr[l]==arr[r])return dp[l][r]=solve(l+1,r-1)+1;
    for(int i=l; i<r; i++){
        dp[l][r]=max(dp[l][r],solve(l,i)+solve(i+1,r));
    }
    return dp[l][r];
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        for(int j=1; j<=n; j++){
            dp[i][j]=-1;
        }
    }
    cout << solve(1,n);

    return 0;
}