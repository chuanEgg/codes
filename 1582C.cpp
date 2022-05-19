#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 2e5+10;
char s[maxn];
int alp[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(alp,0,sizeof(alp));
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n*2; i+=2){
            cin>>s[i];
            alp[s[i]-'a']++;
        }
        bool flag = false;
        char erase1, erase2;
        for(int i=0; i<2*n; i++){
            for(int j=0; j<n && (i-j)>=0 && (i+j)<2*n; j++){
                if(s[i+j]!=s[(i-j)] && flag = false){
                    flag = true;
                    erase1 = s[(i+j)];
                    erase2 = s[(i-j)];
                }
            }
        }
    }
}