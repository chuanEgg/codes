#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if(a.length() != b.length()){
        if(a[0] != '-')
        return a.length()<b.length();
        return a.length()>b.length();
    }else{
        bool flag = 0;
        for(int i=0; i<a.length(); i++){
            if(a[i] == '-'){
                flag = 1;
                continue;
            }
            if(a[i]!=b[i]){
                if(flag)
                return a[i]>b[i];
                return a[i]<b[i];
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        vector<string> vp, vn;
        for(int i=0; i<n; i++){
            string temp;
            cin>>temp;
            if(temp[0] == '-'){
                vn.push_back(temp);
            }else{
                vp.push_back(temp);
            }
        }
        sort(vp.begin(), vp.end(), cmp);
        sort(vn.begin(), vn.end(), cmp);
        for(auto i:vn){
            cout<<i<<"\n";
        }
        for(auto i:vp){
            cout<<i<<"\n";
        }
    }
}