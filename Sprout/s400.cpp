#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
struct pt{
    int x, y;
};
int sign(int a){
    if(!a) return 0;
    return a > 0 ? 1: -1;
}
int ori(pt a, pt o, pt b){
    pt v1 , v2;
    v1.x = a.x - o.x;
    v1.y = a.y - o.y;
    v2.x = b.x - o.x;
    v2.y = b.y - o.y;
    int cross = (v1.x * v2.y) - (v1.y * v2.x);
    // cout << cross <<"\n";
    return sign(cross);
}
int dot(pt a, pt o, pt b){
    pt v1 , v2;
    v1.x = a.x - o.x;
    v1.y = a.y - o.y;
    v2.x = o.x - b.x;
    v2.y = o.y - b.y;
    int res =(v1.x * v2.x) + (v1.y * v2.y); 
    // cout << " "<<res <<"\n";
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pt> s(n);
    vector<int> ans(3);
    for(int i=0; i<n; i++){
        cin >> s[i].x >> s[i].y;
    }
    for(int i=1; i<n-1; i++){
        int temp = ori(s[i-1], s[i], s[i+1]);
        if(temp == 0 && dot(s[i-1], s[i], s[i+1]) < 0){
            ans[2] ++;
        }else{
            ans[temp < 0] ++;
        }
    }
    for(int i=0; i<3; i++){
        cout << ans[i] << (" \n"[i == 2]);
    }
}