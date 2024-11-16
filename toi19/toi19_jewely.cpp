#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll sum,ans;
stack<int>st;
queue<int>q;
string s;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> s;
    s="x"+s;
    for(int i=1; i<=n; i++){
        if(s[i]=='T'){
            if(!st.empty()){
                sum-=st.top();
                st.pop();
            }
            q.push(i);
            sum+=i;
            
        }
        else {
            while(!q.empty()){
                st.push(q.front());
                q.pop();
            }
        }
        ans+=sum;
    }
    cout << ans;

    return 0;
}