#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 50005;
int N, K;
int P[maxn];
 
bool canCover(int d){
    int coverage = P[0] + d;
    int cnt = 1;
    for (int i=1; i<N; i++){
        while (P[i] > coverage){
            coverage = P[i] + d;
            cnt++;
        }
    }
    return (cnt <= K);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> P[i];
    }
    sort(P, P+N);
     
    int l = 0;
    int r = (P[N-1] - P[0]) / K + 1;
    int mn = 2e9;
    while (l < r){
        int mid = (l + r) / 2;
        if (canCover(mid)){
            mn = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << mn << '\n';
     
    return 0;
}