#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
using namespace std;

const int INF = 9e18;
vector<pair<int,int>> point;
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
int get_dis(pair<int,int> a, pair<int,int> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int cut(int l, int r){
    if(l == r) return INF;
    int m = (l+r)/2;
    auto pos = point[m];
    int temp = min(cut(l, m), cut(m+1, r));
    vector<pair<int,int>> combine(r-l+1), v;
    // first_1, end_1, first_2, end_2, output, comp
    merge(point.begin()+l, point.begin()+m+1, point.begin()+m+1, point.begin()+r+1, combine.begin(), cmp);
    for(int i=l; i<=r; i++){
        point[i] = combine[i-l];
        int dis = (point[i].first - pos.first)*(point[i].first - pos.first); 
        if(dis <= temp){
            v.push_back(point[i]);
        }
    }
    int len = v.size();
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            temp = min(temp, get_dis(v[i],v[j]));
            int dis = (v[i].second-v[j].second)*(v[i].second-v[j].second); 
            if(dis > temp)
                break;
        }
    }
    return temp;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        point.push_back({x,y});
    }
    sort(point.begin(), point.end());
    int ans = cut(0, n-1);
    cout << ans <<"\n";
}