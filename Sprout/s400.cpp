#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> Pt;
#define X first
#define Y second

Pt point(int x, int y){
    return make_pair(x, y);
}
int operator*(const Pt& p1, const Pt& p2){
    return p1.X * p2.X + p1.Y * p2.Y;
}
int operator^(const Pt& p1, const Pt& p2){
    return p1.X * p2.Y - p1.Y * p2.X;
}
Pt operator-(const Pt& p1, const Pt& p2){
    return Pt(p1.X - p2.X, p1.Y - p2.Y);
}
int sign(int a){
    if(a == 0) return 0;
    return a > 0 ? 1 : -1;
}
int ori(const Pt &o, const Pt &a, const Pt &b){
    int cross = (a-o) ^ (b-o);
    return sign(cross);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Pt> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i].X >> s[i].Y;
    }
    vector<int> ans(3, 0);
    for(int i=1; i<n-1; i++){
        int res = ori(s[i], s[i-1], s[i+1]);
        // cout << res << " ";
        // cout << (s[i]-s[i-1]) * (s[i+1]-s[i]) << '\n';
        if(res == 0 && (s[i]-s[i-1]) * (s[i+1]-s[i]) < 0){
            ans[2] ++;
        }else if(res){
            ans[res > 0] ++;
        }
    }
    for(int i=0; i<3; i++){
        cout << ans[i] << (" \n"[i == 2]);
    }
}