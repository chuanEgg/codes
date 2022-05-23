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
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> cnt(n);
        for(int& x:v){
            cin>>x;
            cnt[x]++;
        }
        int q;
        cin>>q;
        while(q--){
            
        }
    }
}