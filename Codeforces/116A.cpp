#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int len = s.length();
        int ab = 0, ba = 0;
        for(int i=0; i<len-1; i++){
            if(s[i] == 'a' && s[i+1] == 'b'){
                ab++;
            }
            else if(s[i] == 'b' && s[i+1] == 'a'){
                ba++;
            }
        }
        //cout<<ab<<" "<<ba<<"\n";
        if(ab > ba){
            if(s[0] == 'a'){
                s[0] = 'b';
            }else{
                s[len-1] = 'a';
            }
        }else if(ab < ba){
            if(s[0] == 'b'){
                s[0] = 'a';
            }else{
                s[len-1] = 'b';
            }
        }
        cout<<s<<"\n";
    }
    
}