#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
vector<int>v;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++)v.push_back(i);
    do{
        bool chk=false;
        for(int i=1; i<=m; i++){
            if(v[0]==arr[i]){
                chk=true;
                break;
            }
        }
        if(!chk){
            for(int i:v)cout << i << ' ';
            cout << '\n';
        }
    }while(next_permutation(v.begin(),v.end()));

    return 0;
}
