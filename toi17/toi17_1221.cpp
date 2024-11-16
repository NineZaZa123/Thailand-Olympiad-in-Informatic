#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=501;
int n,m,q;
ll p[N],dis[N][N],cnt[N][N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++)cin >> p[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)continue;
            dis[i][j]=p[i]+p[j];
            cnt[i][j]=2;
        }
    }
    for(int i=1; i<=m; i++){
        ll u,v,w;
        cin >> u >> v >> w;
        dis[u][v]=dis[v][u]=min(dis[u][v],w);
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j)continue;
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    cnt[i][j]=cnt[j][i]=cnt[i][k]+cnt[k][j];
                }
                else if(dis[i][k]+dis[k][j]==dis[i][j]){
                    cnt[i][j]=cnt[j][i]=min(cnt[i][j],cnt[i][k]+cnt[k][j]);
                }
            }
        }
    }
    while(q--){
        int u,v;
        cin >> u >> v;
        cout << dis[u][v] << ' ' << cnt[u][v] << '\n';
    }

    return 0;
}