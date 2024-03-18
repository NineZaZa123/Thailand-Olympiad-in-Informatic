#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=5e4+1;
int n,mxr;
priority_queue<pii,vector<pii>,greater<pii>>pq[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int r,c1,c2;
        cin >> r >> c1 >> c2;
        pq[r].push({c1,c1+c2-1});
        mxr=max(mxr,r);
    }
    for(int i=1; i<=mxr; i++){
        for(int j=1; j<=70; j++){
            if(!pq[i].empty()&&pq[i].top().first<=j&&j<=pq[i].top().second){
                cout << 'x';
                if(j==pq[i].top().second)pq[i].pop();
            }
            else cout << 'o';
        }
        cout << '\n';
    }

    return 0;
}
