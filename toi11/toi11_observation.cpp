#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2001;
int n,m,k;
ll ans=LLONG_MIN;
ll mp[N][N],dpsq[N][N],dptri[N][N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mp[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dptri[i][j]=mp[i][j]+dptri[i][j-1]+dptri[i-1][j-1];
            if(j>1)dptri[i][j]-=dptri[i-1][j-2];
            dpsq[i][j]=mp[i][j]+dpsq[i-1][j]+dpsq[i][j-1]-dpsq[i-1][j-1];
        }
    }
    for(int i=k; i<=n; i++){
        for(int j=k; j<=m; j++){
            ans=max(ans,dptri[i][j]-dpsq[i][j-k]+dpsq[i-k][j-k]-dptri[i-k][j-k]);
        }
    }
    memset(dpsq,0,sizeof(dpsq));
    memset(dptri,0,sizeof(dptri));
    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            dptri[i][j]=mp[i][j]+dptri[i][j+1]+dptri[i-1][j+1];
            if(j<m-1)dptri[i][j]-=dptri[i-1][j+2];
            dpsq[i][j]=mp[i][j]+dpsq[i-1][j]+dpsq[i][j+1]-dpsq[i-1][j+1];
        }
    }
    for(int i=k; i<=n; i++){
        for(int j=1; j<=m-k+1; j++){
            ans=max(ans,dptri[i][j]-dpsq[i][j+k]+dpsq[i-k][j+k]-dptri[i-k][j+k]);
        }
    }
    cout << ans;

    return 0;
}

/*
5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1 
1 1 1 1 1
1 1 1 1 1
*/