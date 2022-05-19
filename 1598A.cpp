#include <iostream>

using namespace std;

bool map[3][101];

int main(){
    ios_base::sync_with_stdio(false);
   cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        bool pass = 1;
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0; i<n; i++){
            if(s1[i]-'0' && s2[i]-'0')
                pass = 0;
        }
        cout<<(pass?"YES":"NO")<<"\n";
    }
}