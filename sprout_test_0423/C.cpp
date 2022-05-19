#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> s(m);
    for(int i=0; i<m; i++){
        cin >> s[i].first >> s[i].second;
    }
    sort(s.begin(), s.end());
    int l = 0, r = n+1;
    s.insert(s.begin(), {0, 0});
    s.insert(s.end(), {n, n});
    auto temp = s;
    while(l<r){
        s = temp;
        int mid = (l+r)/2, used = 0, rr = 0;
        bool flag = 0;
        // cout << mid<<"\n";
        for(int i=1; i<=m; i++){
            if(rr < s[i].first || (s[i+1].first-rr > mid && (s[i].second+mid>s[i+1].first-mid))){
                // cout <<  "\t\t"<<i<<"\n";
                s[i].first -= mid;
                s[i].second += mid;
                used++;
            }
            if(rr < s[i].first){
                flag = 1;
                break;
            }
            rr = max(rr, s[i].second);
        }
        // for(auto i:s){
        //     cout << "\t"<<i.first << " "<<i.second<<"\n";
        // }
        
        if(flag || used > k){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    cout << l <<"\n";
}/*
20 4 2
0 2
3 7
14 16
15 15
*/