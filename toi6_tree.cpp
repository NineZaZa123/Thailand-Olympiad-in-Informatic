#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=1e5+1;
int n;

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  for(int k=1; k<=5; k++){
    cin >> n;
    vector<pii>adj1;
    vector<pii>adj2;
    for(int i=1; i<n; i++){
      int u,v;
      cin >> u >> v;
      adj1.push_back({v,u});
      adj1.push_back({u,v});
    }
    sort(adj1.begin(),adj1.end());
    for(int i=1; i<n; i++){
      int u,v;
      cin >> u >> v;
      adj2.push_back({v,u});
      adj2.push_back({u,v});
    }
    sort(adj2.begin(),adj2.end());
    if(adj1==adj2)cout << 'Y';
    else cout << 'N';
  }

  return 0;
}