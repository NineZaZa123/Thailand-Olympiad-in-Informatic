#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1;
int n;
int hpo,hpe,comboo,comboe;
int arr[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    hpo=hpe=n;
    for(int i=1; i<=2*n; i++){
        int tmp;
        cin >> tmp;
        if(hpe<=0||hpo<=0)continue;
        if(tmp&1){
            comboe=0;
            comboo++;
            if(comboo>=3)hpe-=3;
            else hpe--;
        }
        else{
            comboo=0;
            comboe++;
            if(comboe>=3)hpo-=3;
            else hpo--;
        }
        if(hpo<=0||hpe<=0)cout << (tmp&1) << '\n' << tmp;
    }

    return 0;
}
