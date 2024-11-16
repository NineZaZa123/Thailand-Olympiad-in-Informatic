#include<bits/stdc++.h>
using namespace std;

const int N=3001;
int l,h,n;
int a,b;
int cnt[N],cnt100,cnt50;

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> l >> h >> n;
  cnt100=l;
  for(int i=1; i<=n; i++){
    cin >> a >> b;
    for(int j=1; j<=b&&a+j<=l; j++){
      cnt[a+j]++;
      if(cnt[a+j]==1){
        cnt100--;
        cnt50++;
      }
      if(cnt[a+j]==2){
        cnt50--;
      }
    }
  }
  cout << cnt100*h << ' ' << cnt50*h;

  return 0;
}