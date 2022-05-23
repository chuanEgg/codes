#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> s(n);
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        char c = 'a';
        int ans = n-1;
        for(int i=0; i<26; i++){
            int cnt = 0;
            c = (char)('a'+i);
            //cout<<c<<"\n";
            int l = 0, r = n-1;
            while(l <= r){
                if(s[r] == s[l]){
                    r--;
                    l++;
                }else if(s[l] == c){
                    cnt++;
                    l++;
                }else if(s[r] == c){
                    cnt++;
                    r--;
                }else{
                    cnt=n-1;
                    break;
                }
            }
            ans = min(ans, cnt);
        }
        if(ans == n-1) ans = -1;
        cout<<ans<<"\n";
    }
}