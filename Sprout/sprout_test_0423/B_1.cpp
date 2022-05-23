#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, q, lastmod = -1;
    cin >> k >> q;
    vector<int> s;
    vector<pair<string,int>> Q(q);
    for(int i=0; i<q; i++){
        cin >> Q[i].first;
        if(Q[i].first == "Add"){
            cin >> Q[i].second;
        }else{
            Q[i].second = i;
            if(Q[i].first == "Mod"){
                lastmod = i;
            }
        }
    }
    for(int i=0; i<q; i++){
        if(Q[i].first == "Add"){
            s.push_back(Q[i].second);
        }else if(Q[i].first == "Remove"){
            s.erase(s.begin() + (s.size()+1)/2 -1);
        }else if(Q[i].first == "Reverse"){
            reverse(s.begin(), s.end());
        }else{
            if(i == lastmod && k != 1e9){
                for(auto &i:s){
                    i %= k;
                }
            }
        }
    }
    for(int i:s){
        cout << i <<" ";
    }
    cout <<"\n";
}