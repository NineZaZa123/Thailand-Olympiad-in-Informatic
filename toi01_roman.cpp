#include<bits/stdc++.h>
using namespace std;

int n;
int cnt[6]; // i v x l c

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int m=i;
        if(m>=100){
            cnt[5]+=m/100;
            m%=100;
        }
        if(m>=90){
            cnt[5]++;
            cnt[3]++;
            m-=90;
        }
        if(m>=50){
            cnt[4]++;
            m-=50;
        }
        if(m>=40){
            cnt[4]++;
            cnt[3]++;
            m-=40;
        }
        if(m>=10){
            cnt[3]+=m/10;
            m%=10;
        }
        if(m==9){
            cnt[3]++;
            cnt[1]++;
            m=0;
        }
        if(m>=5){
            cnt[2]++;
            m-=5;
        }
        if(m==4){
            cnt[2]++;
            cnt[1]++;
            m=0;
        }
        if(m>=1){
            cnt[1]+=m;
            m=0;
        }
    }
    for(int i=1; i<=5; i++){
        cout << cnt[i] << ' ';
    }

    return 0;
}
