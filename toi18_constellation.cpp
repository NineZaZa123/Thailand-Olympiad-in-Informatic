#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1501,MOD=1e6+3;
int n,m,k;
ll ans;
ll dp[N][N];
ll qslr[N][N],qsrl[N][N];
string s;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    dp[0][0]=1;
    for(int i=1; i<600; i++){
        dp[i][0]=1;
        for(int j=1; j<=min(i,k); j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
        }
    }
    for(int i=1; i<=n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            qslr[i+600][j+601]=(s[j]=='#');
            qsrl[i+600][j+601]=(s[j]=='#');
        }
    }
    for(int i=1; i<N; i++){
        for(int j=1; j<N; j++){
            qslr[i][j]+=qslr[i-1][j-1];
            qsrl[i][j]+=qsrl[i-1][j+1];
        }
    }
    for(int l=1; l<=n+m; l++){
        for(int i=601; i<=n+600; i++){
            for(int j=601; j<=m+600; j++){
                ll r=qslr[i][j+l]-qslr[i-l-1][j-1];      // top right
                r+=qslr[i+l][j]-qslr[i-1][j-l-1];        // bot left 
                r+=qsrl[i-1][j-l+1]-qsrl[i-l][j];        // top left
                r+=qsrl[i+l-1][j+1]-qsrl[i][j+l];        // bot right
                ans+=dp[r][k];
                ans%=MOD;
            }
        }
    }
    cout << ans;

    return 0;
}