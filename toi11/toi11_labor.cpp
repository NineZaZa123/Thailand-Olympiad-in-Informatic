#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

ll n,m;
vector<ull>v;

bool comp(int a,int b){
  return a>b;
}

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> m >> n;
  for(int i=1; i<=m; i++){
    ull x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(),v.end(),comp);
  ull l=0,r=1e15;
  while(l<=r){
    ull mid=(l+r)/2;
    ll num=n;
    for(int i=0; i<m&&num>0; i++){
      num-=mid/v[i];
    }
    if(num>0){
      l=mid+1;
    }
    else{
      r=mid-1;
    }
  }
  cout << l;

  return 0;
}