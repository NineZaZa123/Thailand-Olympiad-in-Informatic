#include<bits/stdc++.h>
using namespace std;

const int N=300;
int n,mxr;
int arr[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int l,h,r;
        cin >> l >> h >> r;
        mxr=max(mxr,r);
        for(int j=l; j<r; j++){
            arr[j]=max(arr[j],h);
        }
    }
    for(int i=1; i<=mxr; i++){
        if(arr[i]!=arr[i-1])cout << i << ' ' << arr[i] << ' ';
    }

    return 0;
}