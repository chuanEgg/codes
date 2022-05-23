#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        vector<pair<int,int>> ans;
        for(int i=0; i<n-1; i++){
            int pos = i;
            for(int j=i+1;j<n;j++){
                if(s[j] < s[pos]){
                    pos = j;
                }
            }
            if(pos > i){
                ans.push_back({i+1, pos+1});
                int swp = s[pos];
                for(int j=pos; j>i; j--){
                    s[j] = s[j-1];
                }
                s[i] = swp;
            }
        }
        cout << ans.size() <<"\n";
        for(auto i:ans){
            cout << i.first <<" "<<i.second<<" "<<i.second-i.first<<"\n";
        }
    }
}