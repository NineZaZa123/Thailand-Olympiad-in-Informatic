#include<bits/stdc++.h>
using namespace std;

int n,sum;
int ap=500,b=2,bp=800,c=5,cp=1500,d=15,dp=3000;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    sum+=dp*(n/d);
    n%=d;
    if(n==1)sum+=500;
    else if(n==2)sum+=800;
    else if(n==3)sum+=1300;
    else if(n<=5)sum+=1500;
    else if(n==6)sum+=2000;
    else if(n==7)sum+=2300;
    else if(n==8)sum+=2800;
    else sum+=3000;
    cout << sum;

    return 0;
}