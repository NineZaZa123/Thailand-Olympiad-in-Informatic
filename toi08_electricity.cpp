#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=5e5+1;
int n,k;
int arr[N];
deque<pii>dq;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i=2; i<=k+1; i++){
        while(!dq.empty()&&dq.back().second>arr[i]+arr[1])dq.pop_back();
        dq.push_back({i,arr[i]+arr[1]});
    }
    for(int i=k+2; i<=n; i++){
        while(!dq.empty()&&dq.front().first<i-k)dq.pop_front();
        int sum=dq.front().second+arr[i];
        while(!dq.empty()&&dq.back().second>sum)dq.pop_back();
        dq.push_back({i,sum});
    }
    cout << dq.back().second;

    return 0;
}
