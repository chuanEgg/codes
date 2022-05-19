#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> s(n);
        bool flag = 0;
        for(int i=0; i<n; i++){
            cin>>s[i];
            if(i && s[i-1] >= s[i]){
                flag = 1;
            }
        }
        if(n%2==0 || flag){
            cout<<"YES\n";
            continue;
        }else{
            cout<<"NO\n";
        }
    }
}