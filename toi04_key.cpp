#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[3];
string a,b,k;
stack<char>st;

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  cin >> a >> b >> k;
  for(int i=m-1; i>=0; i--){
    for(int j=0; j<n; j++){
      arr[0]=a[j];
      arr[1]=k[i];
      arr[2]=b[j];
      sort(arr,arr+3);
      k[i]=arr[1];
    }
    st.push(k[i]);
  }
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }

  return 0;
}
