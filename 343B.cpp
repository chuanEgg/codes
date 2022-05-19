#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int len = s.length();
    stack<char> st;
    for(int i=0; i<len; i++){
        if(!st.empty() && st.top() == s[i]){
            st.pop();
        }else{
            st.push(s[i]);
            // cout<<s[i]<<"\n";
        }
    }
    if(st.empty()){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}