#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;
int n,q;
int arr[N],qs[N][101];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        for(int j=1; j<=100; j++){
            qs[i][j]=arr[i];
            if(i-j>0)qs[i][j]+=qs[i-j][j];
        }
    }
    while(q--){
        int l,r,m;
        cin >> l >> m >> r;
        if(m<=100){
            int idx=(((r-l)/m)*m)+l;
            cout << qs[idx][m]-qs[max(0,l-m)][m] << ' ';
        }
        else{
            int sum=0;
            for(int i=l; i<=r; i+=m){
                sum+=arr[i];
            }
            cout << sum  << ' ';
        }
    }

    return 0;
}