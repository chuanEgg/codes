#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 3e5 + 10;
string s[maxn];
int cnt[maxn];

int bal(string s){
    int l=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(')
            l++;
        if(s[i]==')')
            l--;
        if(l <0) return -1;
    }
    return l;
}
string rev(string temp){
    string s = temp;
    reverse(s.begin(), s.end());
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(')
            s[i]=')';
        else if(s[i]==')')
            s[i]='(';
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long ans = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
        int temp = bal(s[i]);
        if(temp!=-1) cnt[temp]++;
        //cout<<temp<<"\n";
    }
    for(int i=0; i<n; i++){
        string temp = rev(s[i]);
        int temp2 = bal(temp);
        if(temp2!=-1){
            ans+=cnt[temp2];
        }
        //cout<<temp2<<"\n";
        //cout<<s[i]<<"\n";
    }
    cout<<ans<<"\n";
}