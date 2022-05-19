#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<char> v(27);
        string s;
        for(int i=1; i<=26; i++){
            char temp;
            cin>>temp;
            v[(int)temp-'a'+1] = i;
            //cout<<(int)temp-'a'+1<<"\t"<<i<<"\n";
        }
        cin>>s;
        int len = s.length();
        int ans = 0;
        for(int i=1; i<len; i++){
            ans += abs(v[s[i]-'a'+1]-v[s[i-1]-'a'+1]);
        }
        cout<<ans<<"\n";
    }
}