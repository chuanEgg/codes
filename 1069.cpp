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
    int ans=0, temp = 1;
    char last = s[0];
    for(int i=1; i<s.length(); i++){
        if(s[i] == last){
            temp++;
        }else{
            ans = max(ans, temp);
            temp = 1;
            last = s[i];
        }
    }
    ans = max(ans,temp);
    cout<<ans<<"\n";
}