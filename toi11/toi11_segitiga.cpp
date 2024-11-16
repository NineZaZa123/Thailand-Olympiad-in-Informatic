#include<bits/stdc++.h>
using namespace std;

const int N=256;
int n;
int arr[N];
bool dp[N][N][3];
bool vis[N][N];
string s;

void solve(int l,int r){
    if(l==r){
        dp[l][r][arr[l]]=true;
        return ;
    }
    if(vis[l][r])return ;
    vis[l][r]=true;
    for(int i=l; i<r; i++){
        solve(l,i);
        solve(i+1,r);
        if(dp[l][i][0]&&dp[i+1][r][2])dp[l][r][0]=true;
        if((dp[l][i][0]&&dp[i+1][r][1])||(dp[l][i][1]&&dp[i+1][r][1])||(dp[l][i][1]&&dp[i+1][r][2])||(dp[l][i][2]&&dp[i+1][r][0])||(dp[l][i][2]&&dp[i+1][r][2]))dp[l][r][1]=true;
        if((dp[l][i][0]&&dp[i+1][r][0])||(dp[l][i][1]&&dp[i+1][r][0])||(dp[l][i][2]&&dp[i+1][r][1]))dp[l][r][2]=true;
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    for(int i=1; i<=20; i++){
        cin >> n;
        cin >> s;
        for(int j=0; j<n; j++){
            arr[j+1]=s[j]-'0';
        }
        for(int h=1; h<=n; h++){
            for(int j=1; j<=n; j++){
                for(int k=0; k<=2; k++){
                    dp[h][j][k]=false;
                }
                vis[h][j]=false;
            }
        }
        solve(1,n);
        if(dp[1][n][0])cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}