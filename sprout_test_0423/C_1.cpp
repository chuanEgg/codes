#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e6;
int bit[maxn];
int query(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= i&(-i);
    }
    return res;
}
void update(int i, int val){
    while(i<maxn){
        bit[i] += val;
        i += i&(-i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, k, ml = 1e6+5, mr = -1;
    cin >> n >> m >> k;
    vector<pair<int,int>> s(m);
    for(int i=0; i<m; i++){
        cin >> s[i].first >> s[i].second;
        mr = max(s[i].second, mr);
        ml = min(s[i].first, ml);
    }
    sort(s.begin(), s.end());
    int l = 0, r = n+1;
    s.insert(s.begin(), {0, 0});
    s.insert(s.end(), {n, n});
    auto temp = s;
    while(l<r){
        s = temp;
        int mid = (l+r)/2, used = 0;
        bool flag = 0;
        for(int i=1; i<=m; i++){
            s[i].first -= mid;
            s[i].second += mid;
            s[i].first = max(0, s[i].first);
            update(s[i].first, 1);
            update(s[i].second, -1);
            // cout << i <<"\n";
        }
        for(int i=0; i<n; i++){
            if(query(i) <= 0){
                flag = 1;
                break;
            }
        }
        if(flag){
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