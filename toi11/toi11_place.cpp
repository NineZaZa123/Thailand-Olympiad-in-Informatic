#include<bits/stdc++.h>
#define pii pair<int,pair<int,int>>
using namespace std;

const int N=2e5+1;
long long n,m,ans;
int pa[N];
priority_queue<pii>pq;

int root(int x){
  if(pa[x]==x)return x;
  else return pa[x]=root(pa[x]);
}

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  for(int i=1; i<=n; i++)pa[i]=i;
  for(int i=1; i<=m; i++){
    int u,v,w;
    cin >> u >> v >> w;
    pq.push({w,{u,v}});
  }
  while(!pq.empty()){
    int w=pq.top().first;
    int u=pq.top().second.first;
    int v=pq.top().second.second;
    pq.pop();
    if(root(u)!=root(v)){
      ans+=w-1;
      pa[root(u)]=root(v);
    }
  }
  cout << ans;

  return 0;
}