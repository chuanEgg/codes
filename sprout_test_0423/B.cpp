#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, q;
    cin >> k >> q;
    vector<int> s, Q;
    while(q--){
        string o;
        int x;
        cin >> o;
        if(o[0] == 'A'){
            cin >> x;
            s.push_back(x);
        }else if(o == "Remove"){
            s.erase(s.begin() + (s.size()+1)/2 -1);
        }else if(o[0] == 'M'){
            if(k == 1e9) continue;
            for(auto &i:s){
                i %= k;
            }
        }else{
            reverse(s.begin(), s.end());
        }
    }
    for(int i:s){
        cout << i <<" ";
    }
    cout <<"\n";
}