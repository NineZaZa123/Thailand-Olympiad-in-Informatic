#include<bits/stdc++.h>
using namespace std;

const int N=2e6+1;
int n;
int mx;
stack<int>st;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(st.empty()){
            st.push(x);
        }
        else{
            if(x>st.top()){
                mx=max(mx,st.top());
                st.push(x);
            }
            else if(x==st.top()){
                st.pop();
            }
            else{
                mx=max(mx,x);
            }
        }
    }
    cout << mx;

    return 0;
}