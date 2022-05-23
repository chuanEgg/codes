#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(char a, char b){
    if((a == 'b'&&b=='c')||(a == 'c'&&b=='b')){
        return a>b;
    }
    return a<b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        string s,t;
        cin>>s>>t;
        bool flag = 0;
        for(auto i:s){
            if(i == 'a') flag = 1;
        }
        if(t == "abc" && flag){
            sort(s.begin(), s.end(), cmp);
        }else{
            sort(s.begin(), s.end());
        }
        cout<<s<<"\n";
    }
}