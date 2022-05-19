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
        int a=0, b=0, c=0;
        for(int i=0; i<len; i++){
            if(s[i] == 'A'){
                a++;
            }else if(s[i]=='B'){
                b++;
            }else{
                c++;
            }
        }
        if(b != len/2 || len%2){
            cout << "NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}