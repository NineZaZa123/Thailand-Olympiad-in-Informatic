#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n;
int x,y;
int mx;
int mp[21][21];
queue<pair<int,int>>q;

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> n >> x >> y;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin >> mp[i][j];
    }
  }
  q.push({y,x});
  while(!q.empty()){
    y=q.front().first;
    x=q.front().second;
    mx=max(mx,mp[y][x]);
    q.pop();
    for(int i=0; i<4; i++){
      int yy=y+dir[i][0];
      int xx=x+dir[i][1];
      if(mp[yy][xx]==100||yy>n||yy<1||xx>n||xx<1||mp[yy][xx]<=mp[y][x])continue;
      q.push({yy,xx});
    }
  }
  cout << mx;

  return 0;
}
