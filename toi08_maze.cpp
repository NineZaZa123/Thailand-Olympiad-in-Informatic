#include<bits/stdc++.h>
#define pii pair<int,pair<int,int>>
using namespace std;

const int N=155;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
int ex,ey;
int s;
int mp[N][N];
int dp1[N][N],dp2[N][N];
int wallcnt,mn=INT_MAX;
queue<pii>q;

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  cin >> ey >> ex; q.push({0,{ey,ex}});
  //cout <<s << ' ' << ex << '\n';
  cin >> ey >> ex;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin >> mp[i][j];
      dp1[i][j]=INT_MAX;
      dp2[i][j]=INT_MAX;
    }
  }
  while(!q.empty()){
    int y=q.front().second.first;
    int x=q.front().second.second;
    int cnt=q.front().first;
    q.pop();
    if(y==ey&&x==ex){
      cout << cnt;
      return 0;
    }
    for(int i=0; i<4; i++){
      int xx=x+dir[i][0];
      int yy=y+dir[i][1];
      if(xx>m||xx<1||yy>n||yy<1)continue;
      if(dp1[yy][xx]>cnt+1){
        dp1[yy][xx]=cnt+1;
        if(mp[yy][xx]!=0)q.push({cnt+1,{yy,xx}});
      }
    }
  }
  q.push({1,{ey,ex}});
  while(!q.empty()){
    int cnt=q.front().first;
    int y=q.front().second.first;
    int x=q.front().second.second;
    q.pop();
    for(int i=0; i<4; i++){
      int yy=y+dir[i][0];
      int xx=x+dir[i][1];
      if(yy>n||yy<1||xx>m||xx<1)continue;
      if(dp2[yy][xx]>cnt+1){
        dp2[yy][xx]=cnt+1;
        if(mp[yy][xx]!=0)q.push({cnt+1,{yy,xx}});
        else if(dp1[yy][xx]<INT_MAX){
          mn=min(mn,dp2[yy][xx]+dp1[yy][xx]);
          wallcnt++;
        }
      }
    }
  }
  cout << wallcnt << '\n' << mn;

  return 0;
}
