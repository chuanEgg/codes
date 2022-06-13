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
    if(abs(a) <= 0) return 0;
    return a > 0 ? 1 : -1;
}
int ori(const Pt &o, const Pt &a, const Pt &b){
    int cross = (a-o) ^ (b-o);
    return sign(cross);
}
vector<Pt> solv(vector<Pt> dots){
    if(dots.size() == 1) return {dots[0]};
    int n = dots.size();
    sort(dots.begin(), dots.end());
    vector<Pt> stk(1, dots[0]);
    for(int i=1; i<n; i++){
        while(stk.size() > 1 && ori(stk[stk.size()-2], stk.back(), dots[i]) <= 0){
            stk.pop_back();
        }
        stk.push_back(dots[i]);
    }
    int t = stk.size();
    for(int i=n-2; i>=0; i--){
        while(stk.size() > t && ori(stk[stk.size()-2], stk.back(), dots[i]) <= 0){
            stk.pop_back();
        }
        stk.push_back(dots[i]);
    }
    stk.pop_back();
    return stk;
}
int calc(vector<Pt>& dots){
    dots.push_back(dots.front());
    int res = 0.0;
    for(int i=0; i<dots.size()-1; i++){
        res += dots[i].X*dots[i+1].Y;
    }
    for(int i=0; i<dots.size()-1; i++){
        res += -(dots[i].Y*dots[i+1].X);
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<Pt> dots(n);
        for(int i=0 ;i <n; i++){
            cin >> dots[i].X >> dots[i].Y;
        }
        auto res = solv(dots);
        // for(auto i:res){
        //     cout << i.X << ' '<<i.Y<<'\n';
        // }
        int temp = calc(res);
        if(temp % 2)
            cout << (temp>>1) << ".5\n";
        else
            cout << (temp>>1) << ".0\n";
    }
}