#include<bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<pii,pair<pii,pii>>
using namespace std;

const int N=1501;
int n;
int xt,yt,x,y;
vector<pii>a,b,c,d,ab;
vector<piii>abpos;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> xt >> yt >> n;
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        a.push_back({x,y});
    }
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        b.push_back({x,y});
    }
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        c.push_back({x,y});
    }
    for(int i=1; i<=n; i++){
        cin >> x >> y;
        d.push_back({x,y});
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            abpos.push_back({{a[i].first+b[j].first,a[i].second+b[j].second},{{a[i].first,a[i].second},{b[j].first,b[j].second}}});
        }
    }
    sort(abpos.begin(),abpos.end());
    for(int i=0; i<abpos.size(); i++){
        ab.push_back({abpos[i].first});
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int xx=c[i].first+d[j].first,yy=c[i].second+d[j].second;
            pii tmp={xt-xx,yt-yy};
            int idx=lower_bound(ab.begin(),ab.end(),tmp)-ab.begin();
            if(ab[idx].first+xx==xt&&ab[idx].second+yy==yt){
                cout << abpos[idx].second.first.first << ' ' << abpos[idx].second.first.second << '\n';
                cout << abpos[idx].second.second.first << ' ' << abpos[idx].second.second.second << '\n';
                cout << c[i].first << ' ' << c[i].second << '\n';
                cout << d[j].first << ' ' << d[j].second;
                break;
            }
        }
    }

    return 0;
}