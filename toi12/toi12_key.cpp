#include<bits/stdc++.h>
using namespace std;

const int N=2001;
int q;
bitset<N>vis;
string a,b,s;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> a >> b >> q;
    while(q--){
        cin >> s;
        int idxa=0,idxb=0;
        for(int i=0; i<s.size(); i++)vis[i]=false;
        for(int i=0; i<s.size(); i++){
            if(s[i]==a[idxa]){
                vis[i]=true;
                idxa++;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(vis[i])continue;
            if(s[i]==b[idxb])idxb++;
        }
        if(idxa==a.size()&&idxb==b.size())cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}