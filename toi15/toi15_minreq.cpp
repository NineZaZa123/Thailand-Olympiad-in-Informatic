#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e7+1;
int n,m,q;
ll lif[11],asst[11],stdn[N],t[11],st[11];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++)cin >> lif[i];
    for(int i=1; i<=n; i++)cin >> asst[i];
    for(int i=1; i<=m; i++){
        cin >> stdn[i];
        stdn[i]+=stdn[i-1];
    }
    for(int i=1; i<=q; i++)cin >> t[i];
    sort(lif+1,lif+n+1);
    sort(asst+1,asst+n+1);
    for(int i=1; i<=q; i++){
        for(int j=0; j<n; j++)cin >> st[j];
        st[n]=m;
        bool chk=true;
        do{
            for(int j=1; j<=n; j++){
                int pos=st[j-1],cnt=0;
                while(pos<st[j]){
                    pos=upper_bound(stdn+pos,stdn+st[j],stdn[pos-1]+lif[j]-asst[j])-stdn;
                    cnt++;
                    if(cnt>t[i]){
                        chk=false;
                        break;
                    }
                }
            }
        }while(!chk&&next_permutation(asst+1,asst+n+1));
        if(chk)cout << "P\n";
        else cout << "F\n";
    }

    return 0;
}