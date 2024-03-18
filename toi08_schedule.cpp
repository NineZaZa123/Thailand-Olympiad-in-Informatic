#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=1001;
int n,m;
int arr[N][2];
pii dp[N][N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> m >> n;
    for(int i=1; i<=n; i++)cin >> arr[i][0];
    for(int i=1; i<=n; i++)cin >> arr[i][1];
    dp[0][0]={1,0};
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(!i&&!j)continue;
            int day1=0,day2=0,t1=0,t2=0;
            if(i){
                day1=dp[i-1][j].first;
                t1=dp[i-1][j].second;
            }
            if(t1+arr[i][0]>m){
                day1++;
                t1=arr[i][0];
            }
            else t1+=arr[i][0];
            if(j){
                day2=dp[i][j-1].first;
                t2=dp[i][j-1].second;
            }
            if(t2+arr[j][1]>m){
                day2++;
                t2=arr[j][1];
            }
            else t2+=arr[j][1];
            if(!j)dp[i][j]={day1,t1};
            else if(!i)dp[i][j]={day2,t2};
            else {
                if(day1<day2||(day1==day2&&t1<t2))dp[i][j]={day1,t1};
                else dp[i][j]={day2,t2};
            }
        }
    }
    cout << dp[n][n].first << '\n' << dp[n][n].second;

    return 0;
}
