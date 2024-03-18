#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

const int N=5e6+2;
int n,k;
int arr[N];
std::vector<int>v,ans;

int main(){
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);
    std::cin >> n >> k;
    for(int i=1; i<=n+1; i++){
        if(i<=n)std::cin >> arr[i];
        if(i==1)continue;
        if(arr[i-2]<arr[i-1]&&arr[i-1]>arr[i])v.push_back(arr[i-1]);
    }
    if(v.empty()){
        std::cout << -1;
        return 0;
    }
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=v.size()-1; i>=0&&cnt<k; i--){
        if(i>0&&v[i]==v[i-1])continue;
        ans.push_back(v[i]);
        cnt++;
    }
    if(cnt<k)for(int i=ans.size()-1; i>=0; i--)std::cout << ans[i] << '\n';
    else for(int i:ans)std::cout << i << '\n';

    return 0;
}