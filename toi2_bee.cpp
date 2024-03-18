#include<bits/stdc++.h>
using namespace std;

int n;
int dp[25][2];

void solve(int s,int w,int y){
  dp[y][0]=w;
  dp[y][1]=s+w+1;
  if(y==24)return ;
  solve(w,s+w+1,y+1);
}

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  solve(0,1,0);
  do{
    cin >> n;
    if(n!=-1)cout << dp[n][0] << ' ' << dp[n][1] << '\n';
  }
  while(n!=-1);

  return 0;
}