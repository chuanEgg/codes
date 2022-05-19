#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(pair<int,char> a, pair<int,char> b){
    if(a.second != b.second){
        return (int)a.second < (int)b.second;
    }else{
        return a.first<b.first;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,char>> v(n+1);
        vector<int> cnt(n+1,0);
        for(int i=1; i<=n; i++){
            cin>>v[i].first;
        }
        for(int i=1; i<=n; i++){
            cin>>v[i].second;
        }
        sort(v.begin(), v.end(), cmp);
        // for(auto i:v){
        //     cout<<i.first<<i.second<<" ";
        // }
        // cout<<"\n";
        bool flag = 0;
        for(int i=1; i<=n; i++){
            if(v[i].first < i&& v[i].second == 'B')
            {
                flag = 1;
            }
            if(v[i].first > i && v[i].second == 'R'){
                flag = 1;
            }
        }
        if(flag){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}