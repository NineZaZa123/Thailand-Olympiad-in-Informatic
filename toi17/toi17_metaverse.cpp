#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pii pair<int,int>
using namespace std;

const int N=2e4+5;
int n,m,k,p;
pii st[N],ed[N];
int dis[N][20];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k >> p;
    st[0]=ed[0]={1,1};
    st[k+1]=ed[k+1]={n,m};
    for(int i=1; i<=k; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        st[i]={x1,y1};
        ed[i]={x2,y2};
    }
    for(int i=1; i<=k+1; i++){
        dis[i][0]=abs(st[0].first-st[i].first)+abs(st[0].second-st[i].second);
    }
    for(int ps=1; ps<=p; ps++){
        for(int i=1; i<=k+1; i++){
            dis[i][ps]=INT_MAX;
            for(int j=0; j<=k+1; j++){
                if(i==j)continue;
                int w=abs(st[i].first-ed[j].first)+abs(st[i].second-ed[j].second);
                if(dis[j][ps-1]+w<dis[i][ps])dis[i][ps]=dis[j][ps-1]+w;
            }
        }
    }
    int ans=INT_MAX,ansp;
    for(int i=1; i<=p; i++){
        if(dis[k+1][i]<ans){
            ans=dis[k+1][i];
            ansp=i;
        }
    }
    cout << ans << ' ' << ansp;

    return 0;
}