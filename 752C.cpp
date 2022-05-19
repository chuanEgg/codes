#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> s(n+1);
        bool ans = 1;
        for(int i=1; i<=n; i++){
            cin>>s[i];
            bool pass = 0;
            for(int j=2; ans && s[i]+1 >= j && j<=i+1 ; j++){
                if(s[i]%j != 0){
                    pass = 1;
                    break;
                }
            }
            if(!pass) ans = 0;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}