#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> s;
    string ss=s+s;
    for(int i=1; i<=n; i++){
        if(!(n%i)&&ss.substr(i,n)==s){
            cout << i;
            break;
        }
    }

    return 0;
}