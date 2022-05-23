#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iomanip>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >>k;
    vector<pair<int,int>> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i].first >> s[i].second;
    }
    double l = 0, r = 1e18;
    for(int i=0; i<100; i++){
        double m = (l+r)/2;
        priority_queue<double> pq;
        for(int i=0; i<n; i++){
            pq.push(s[i].first - s[i].second*m);
            // cout << s[i].first - s[i].second*m<<"\n";
        }
        double sum = 0;
        for(int i=0; i<k ;i++){
            sum += pq.top();
            pq.pop();
        }
        // cout << m <<"\t"<<sum<<"\n";
        if(sum <= 0){
            r = m;
        }else{
            l = m;
        }
    }
    cout <<fixed << setprecision(12)<< l <<"\n";
}