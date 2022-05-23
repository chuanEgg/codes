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
        string s;
        cin>>s;
        int len = s.length();
        int minc = 26+'a';
        int pos;
        for(int i=0; i<len; i++){
            if((int)s[i] < minc){
                pos = i;
                minc = (int)s[i];
            }
        }
        cout<<(char)minc<<" ";
        for(int i=0; i<len; i++){
            if(i != pos){
                cout<<s[i];
            }
        }
        cout<<"\n";
    }
}