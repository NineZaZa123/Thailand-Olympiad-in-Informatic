#include<bits/stdc++.h>
using namespace std;

string s,s2;
stack<char>st;
stack<int>st2;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> s;
    for(char ch:s){
        if('1'<=ch&&ch<='3'){
            while(!st.empty()&&ch<=st.top()&&st.top()!='['){
                s2+=st.top();
                st.pop();
            }
            st.push(ch);
        }
        else if(ch=='[')st.push(ch);
        else if(ch==']'){
            while(st.top()!='['){
                s2+=st.top();
                st.pop();
            }
            st.pop();
        }
        else s2+=ch;
    }
    while(!st.empty()){
        s2+=st.top();
        st.pop();
    }
    for(char ch:s2){
        if('A'<=ch&&ch<='Z')st2.push(20);
        else{
            int b=st2.top();
            st2.pop();
            int a=st2.top();
            st2.pop();
            if(ch=='1')st2.push((a+b)+((a+b)*4/100));
            else if(ch=='2')st2.push((a+b)+((a+b)*8/100));
            else st2.push((a+b)+((a+b)*16/100));
        }
    }
    cout << st2.top();

    return 0;
}