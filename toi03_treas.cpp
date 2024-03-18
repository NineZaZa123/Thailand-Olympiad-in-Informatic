#include<bits/stdc++.h>
using namespace std;

double x,y;
string cmd;

int main(){
  ios_base::sync_with_stdio(0),cin.tie(0);
  while(1){
    cin >> cmd;
    if(cmd=="*")break;
    string num,dir;
    for(int j=0; j<cmd.size(); j++){
      if(cmd[j]>='0'&&cmd[j]<='9')num+=cmd[j];
      else dir+=cmd[j];
    }
    double tmp=stoi(num);
    if(dir=="NE"||dir=="SE"||dir=="SW"||dir=="NW")tmp=sqrt((tmp*tmp)/2);;
    if(dir=="N")y+=tmp;
    else if(dir=="NE"){x+=tmp; y+=tmp;}
    else if(dir=="E")x+=tmp;
    else if(dir=="SE"){x+=tmp; y-=tmp;}
    else if(dir=="S")y-=tmp;
    else if(dir=="SW"){x-=tmp; y-=tmp;}
    else if(dir=="W")x-=tmp;
    else{x-=tmp; y+=tmp;}
  }
  cout << fixed << setprecision(3) << x << ' ' << y << '\n' << sqrt((x*x)+(y*y));

  return 0;
}
