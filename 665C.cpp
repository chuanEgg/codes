#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int len = s.length();
    for (int i=1; i<len; i++){
        if (s[i] == s[i-1]){
            s[i] = (char)'a'+(s[i-1]-'a'+1)%26;
            if (i+1 < s.length() && s[i] == s[i+1])
                s[i] = (char)'a'+(s[i]-'a'+1)%26;
        }
    }
    cout<<s<<"\n";
}