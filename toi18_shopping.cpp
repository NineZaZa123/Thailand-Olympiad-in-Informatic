#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+1;
int n,m;
ll price[N],point[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        price[i]=price[i-1];
        point[i]=point[i-1];
        if(tmp>=0)point[i]+=tmp;
        else price[i]+=-tmp;
    }
    for(int i=1; i<=m; i++){
        int st,mon;
        cin >> st >> mon;
        st++;
        int ed=lower_bound(price+1,price+n+1,mon+price[st-1])-price-1;
        cout << point[ed]-point[st-1] << '\n';
    }

    return 0;
}