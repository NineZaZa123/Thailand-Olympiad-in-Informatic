#include<bits/stdc++.h>
using namespace std;

int n;
int num[3]={6,9,20};
bool vis[101];
vector<int>v;
queue<int>q;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    q.push(0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u)v.push_back(u);
        for(int i=0; i<3; i++){
            if(u+num[i]>n||vis[u+num[i]])continue;
            vis[u+num[i]]=true;
            q.push(u+num[i]);
        }
    }
    sort(v.begin(),v.end());
    if(!v.empty())for(int i:v)cout << i << '\n';
    else cout << "no";

    return 0;
}