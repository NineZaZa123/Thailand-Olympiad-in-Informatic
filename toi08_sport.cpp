#include<bits/stdc++.h>
using namespace std;

int n;
int a,b;

void solve(int win, int loss, string s){
  if(win==n||loss==n){
    cout << s << '\n';
    return;
  }
  solve(win+1,loss,s+"W ");
  solve(win,loss+1,s+"L ");
}

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> n >> a >> b;
  solve(a+1,b,"W ");
  solve(a,b+1,"L ");

  return 0;
}
