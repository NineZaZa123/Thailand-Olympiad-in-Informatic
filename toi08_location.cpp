#include<bits/stdc++.h>
using namespace std;

const int N=1001;
int n,m,k;
int mx;
int arr[N][N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
          cin >> arr[i][j];
    }
    }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
    }
  }
  for(int i=k; i<=n; i++){
    for(int j=k; j<=m; j++){
      mx=max(mx,arr[i][j]-arr[i-k][j]-arr[i][j-k]+arr[i-k][j-k]);
    }
  }
  cout << mx;

  return 0;
}
