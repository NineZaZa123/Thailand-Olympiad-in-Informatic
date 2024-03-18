#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N=5e5+1;
int n;
ll mnh=LLONG_MAX;
ll qsh[N],qsl[N];
pair<ll,ll>arr[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)cin >> arr[i].second;
    for(int i=1; i<=n; i++)cin >> arr[i].first;
    sort(arr+1,arr+n+1);
    for(int i=1; i<=n; i++){
        mnh=min(mnh,arr[i].second);
        qsh[i]=qsh[i-1]+arr[i].second;
        qsl[i]=qsl[i-1]+arr[i].first;
    }
    ll mnl=0,mnt=LLONG_MAX;
    for(int i=n; i>=1; i--){
        ll level=arr[i].first;
        if(level>mnh)continue;
        ll hight=arr[i].second;
        ll l=qsl[i-1]+(qsh[i-1]-(level*(i-1)));
        ll r=(qsl[n]-qsl[i])-(level*(n-i));
        if(l+r<=mnt){
            mnt=l+r;
            mnl=level;
        }
    }
    cout << mnl << ' ' << mnt;

    return 0;
}