#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=1e5+9;
int k,m,n,l;
int cat2[N],p[31];
pii cat[N];
string s;
set<int>ans;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> k >> m;
    p[0]=1;
    for(int i=1; i<30; i++){
        p[i]=p[i-1]*2;
    }
    for(int i=1; i<=k; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            if(s[j]=='1')cat[i].first|=p[j];
        }
        cat[i].second=i;
    }
    sort(cat+1,cat+k+1);
    for(int i=1; i<=k; i++)cat2[i]=cat[i].first;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> l >> s;
        int hsh=0;
        for(int j=0; j<m; j++){
            if(s[j]=='1')hsh|=p[j];
        }
        int idx=lower_bound(cat2+1,cat2+k+1,hsh)-cat2;
        if(idx<=k&&cat2[idx]==hsh)ans.insert(cat[idx].second);
        for(int j=m; j<l; j++){
            hsh>>=1;
            if(s[j]=='1')hsh|=p[m-1];
            idx=lower_bound(cat2+1,cat2+k+1,hsh)-cat2;
            if(idx<=k&&cat2[idx]==hsh)ans.insert(cat[idx].second);
        }
        if(ans.empty())cout << "OK";
        else for(int i:ans)cout << i << ' ';
        cout << '\n';
        ans.clear();
    }

    return 0;
}