#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxn = 1e5+5;
typedef pair<double,double> Pt;
#define X first
#define Y second
Pt s[maxn];
Pt p, q;

Pt point(int x, int y){
    return make_pair(x, y);
}
double operator*(const Pt& p1, const Pt& p2){
    return p1.X * p2.X + p1.Y * p2.Y;
}
int operator^(const Pt& p1, const Pt& p2){
    return p1.X * p2.Y - p1.Y * p2.X;
}
Pt operator-(const Pt& p1, const Pt& p2){
    return Pt(p1.X - p2.X, p1.Y - p2.Y);
}
Pt operator+(const Pt& p1, const Pt& p2){
    return Pt(p1.X +p2.X, p1.Y + p2.Y);
}
int sign(int a){
    if(abs(a) <= 0) return 0;
    return a > 0 ? 1 : -1;
}
int ori(const Pt &o, const Pt &a, const Pt &b){
    int cross = (a-o) ^ (b-o);
    return sign(cross);
}
double calc(vector<Pt>& dots){
    // dots.push_back(dots.front());
    double res = 0.0;
    for(int i=0; i<dots.size()-1; i++){
        res += dots[i].X*dots[i+1].Y;
    }
    for(int i=0; i<dots.size()-1; i++){
        res += -(dots[i].Y*dots[i+1].X);
    }
    return res;
}
double dis(const Pt &a){
    return (a.X)*(a.X) + (a.Y)*(a.Y);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Pt> temp;
    for(int i=0; i<n; i++){
        cin >> s[i].X >> s[i].Y;
        temp.push_back(s[i]);
    }
    temp.push_back(s[0]);
    double ref = 0.5*abs(calc(temp));
    cin >> p.X >> p.Y >> q.X >> q.Y;
    Pt v0 = q - p, mn, mx;
    int  mnd = 2e10, mxd = -2e10;
    int temp1 = 0, temp2 = n-1;
    int dis0 = (p.X-q.X)*(p.X-q.X) + (p.Y-q.Y)*(p.Y-q.Y);
    // cout << v0.X << ' '<<v0.Y <<"\n" << dis0 <<'\n';
    vector<Pt> project(n);
    for(int i=0; i<n; i++){
        Pt v1 = s[i] - p;
        project[i] = {v0*v1 / dis0 * v0.X, v0*v1 / dis0 * v0.Y};
        project[i] = project[i] + p;
        // cout << v1.X << ' '<<v1.Y <<" (v1)\n";
        // // cout << '\t'<<v0*v1<<'\n';
        // // cout << '\t'<<v0*v1/dis0<<'\n';
        if(v0*v1 < mnd || (v0*v1 == mnd && dis(s[i]-project[i]) < dis(s[temp2]-mn))){
            mn = project[i];
            mnd = v0*v1;
            temp2 = i;
        }
        if(v0*v1 > mxd || (v0*v1 == mxd && dis(s[i]-project[i]) < dis(s[temp1]-mx))){
            mx = project[i];
            mxd = v0*v1;
            temp1 = i;
        }
        // cout << dis(project -p) <<'\n';
        // cout << project[i].X << ' '<<project[i].Y <<'\n';
    }
    // cout <<'\n';
    // cout << mx.X <<' '<< mx.Y << '\t'<<mn.X<<' '<<mn.Y<<'\n';
    // cout << temp1 << ' ' << temp2 <<'\n';
    vector<Pt> dots;
    dots.push_back(mx);
    vector<int> check(n, 0);
    if(dis(s[(temp1+1)%n]-project[(temp1+1)%n]) > dis(s[temp1]-project[temp1]) || (dis(s[((temp1-1)+n)%n]-project[((temp1-1)+n)%n]) < dis(s[temp1]-project[temp1]))){
        if(temp1 > temp2){
            for(int i=temp1; i>=temp2; i--){
                dots.push_back(s[i]);
                check[i] = 1;
            }
        }else{
            for(int i=temp1; i>=0; i--){
                dots.push_back(s[i]);
                check[i] = 1;
            }
            for(int i=n-1; i>=temp2; i--){
                dots.push_back(s[i]);
                check[i] = 1;
            }
        }
    }else{
        if(temp1 < temp2){
            for(int i=temp1; i<=temp2; i++){
                dots.push_back(s[i]);
                check[i] = 1;
            }
        }else{
            for(int i=temp1; i<n; i++){
                dots.push_back(s[i]);
                check[i] = 1;
            }
            for(int i=0; i<=temp2; i++){
                dots.push_back(s[i]);
                check[i] = 1;
            }
        }
    }
    dots.push_back(mn);
    dots.push_back(mx);
    // cout << "\n\n";
    for(auto p:dots){
        cout << p.X << ' '<<p.Y<<'\n';
    }
    // Pt res = mx - mn;
    bool flag = 1;
    for(int i=0; i<n; i++){
        if(!check[i]){
            flag = 0;
            break;
        }
    }
    double res = 0.5*abs(calc(dots));
    // if(flag) res -= ref;
    
    cout << fixed << setprecision(10) <<res <<'\n';
}