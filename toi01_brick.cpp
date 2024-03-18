#include<bits/stdc++.h>
using namespace std;

const int N=21;
int n,m;
string s,mp[N];
int arr[N],mn[N],mpn[N][N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++)mn[i]=n+1;
    for(int i=1; i<=n; i++){
        cin >> s;
        mp[i]="X"+s;
        for(int j=1; j<=m; j++){
            if(mp[i][j]=='O')mn[j]=min(mn[j],i);
        }
    }
    for(int i=1; i<=m; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i<mn[j]&&i>=mn[j]-arr[j])cout << '#';
            else cout << mp[i][j];
        }
        cout << '\n';
    }

    return 0;
}
