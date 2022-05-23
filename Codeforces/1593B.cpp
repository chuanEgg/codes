#include <iostream>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len = s.length();
        int cnt = 19, pos;
        char last;
        for(int i=len-1; i>0; i--){
            if(s[i]=='5'){
                for(int j=i-1; j>=0; j--){
                    if(s[j]=='2'||s[j]=='7'){
                        cnt = min((-1-j-1+len), cnt);
                        break;
                    }
                }
            }
            if(s[i]=='0'){
                for(int j=i-1; j>=0; j--){
                    if(s[j]=='0'||s[j]=='5'){
                        cnt = min((-1-j-1+len), cnt);
                        break;
                    }
                }
            }
        }
        cout<<cnt<<"\n";
    }
}