#include<bits/stdc++.h>
#define pii pair<pair<int,int>,string>
using namespace std;

const int N=26;
int n,m,q;
string s,mp[N];
vector<pii>v;

char func(char ch){
    if('A'<=ch&&ch<='Z')return ch+('a'-'A');
    else return ch;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> mp[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            string tmp,tmp2;
            for(int k=j; k<m; k++){
                tmp+=func(mp[i][k]);
                tmp2=tmp;
                v.push_back({{i,j},tmp});
                reverse(tmp2.begin(),tmp2.end());
                v.push_back({{i,k},tmp2});
            }
            tmp.clear();
            for(int k=i; k<n; k++){
                tmp+=func(mp[k][j]);
                tmp2=tmp;
                v.push_back({{i,j},tmp});
                reverse(tmp2.begin(),tmp2.end());
                v.push_back({{k,j},tmp2});
            }
            tmp.clear();
            for(int k=i,h=j; k<n&&h<m; k++,h++){
                tmp+=func(mp[k][h]);
                tmp2=tmp;
                v.push_back({{i,j},tmp});
                reverse(tmp2.begin(),tmp2.end());
                v.push_back({{k,h},tmp2});
            }
        }
    }
    sort(v.begin(),v.end());
    cin >> q;
    while(q--){
        cin >> s;
        string tmp;
        for(char ch:s){
            tmp+=func(ch);
        }
        for(pii ss:v){
            if(tmp==ss.second){
                cout << ss.first.first << ' ' << ss.first.second << '\n';
                break;
            }
        }
    }

    return 0;
}