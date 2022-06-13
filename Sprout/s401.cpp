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
bool btw(const Pt &a, const Pt &b, const Pt &c){
    if(ori(a, b, c) != 0)
        return 0;
    return sign((c-a) * (c-b)) <=0;
}
bool banana(const Pt &p1, const Pt &p2, const Pt &p3, const Pt &p4){
    int a123 = ori(p1, p2, p3);
    int a124 = ori(p1, p2, p4);
    int a341 = ori(p3, p4, p1);
    int a342 = ori(p3, p4, p2);
    if(a123 == 0 && a124 == 0){
        return btw(p1, p2, p3) || btw(p1, p2, p4) || btw(p3, p4, p1) || btw(p3, p4, p2);
    }
    return a123 * a124 <= 0 && a341 * a342 <= 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        Pt a, b, c, d;
        cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> d.X >> d.Y;
        cout << (banana(a, b, c, d)?"Yes":"No") <<'\n';
    }
}