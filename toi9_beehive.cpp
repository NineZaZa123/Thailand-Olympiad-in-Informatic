#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,pair<int,int>>
using namespace std;

const int N=1001;
int n,m;
ll sumway,mx;
ll mp[N][N];
ll dis[N][N];
ll way[N][N];

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin >> mp[i][j];
      if(i==1){
        dis[i][j]=mp[i][j];
        way[i][j]=1;
      }
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      int x;
      if(i&1)x=-1;
      else x=1;
      if(dis[i-1][j]>dis[i-1][j+x]){
        dis[i][j]=dis[i-1][j]+mp[i][j];
        way[i][j]+=way[i-1][j];
      }
      else if(dis[i-1][j]<dis[i-1][j+x]){
        dis[i][j]=dis[i-1][j+x]+mp[i][j];
        way[i][j]+=way[i-1][j+x];
      }
      else{
        dis[i][j]=dis[i-1][j]+mp[i][j];
        way[i][j]+=way[i-1][j]+way[i-1][j+x];
      }
      if(i==n){
        if(dis[n][j]>mx){
          mx=dis[n][j];
          sumway=way[n][j];
        }
        else if(dis[n][j]==mx){
          sumway+=way[n][j];
        }
      }
    }
  }
  cout << mx << ' ' << sumway;

  return 0;
}