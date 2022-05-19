#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int len = s.length();
        bool flag = 0;
        if(len % 2){
            flag = 1;
        }else{
            for(int i=0; i<s.length()/2; i++){
                if(s[i] != s[i+len/2]){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}