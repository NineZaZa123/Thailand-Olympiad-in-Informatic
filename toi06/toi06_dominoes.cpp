#include<bits/stdc++.h>
using namespace std;

int n;
vector<string>v;

void solve(int cnt){
  if(cnt>n)return ;
  if(cnt==n){
    for(int i=0; i<v.size(); i++)cout << v[i] << '\n';
    cout << "E\n";
  }
  else{
    v.push_back("--");
    solve(cnt+1);
    v.pop_back();
    v.push_back("||");
    solve(cnt+2);
    v.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  solve(0);

  return 0;
}