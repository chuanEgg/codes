#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int g, n, m[5], t, mx, a[5], ans, sz, b[5];
queue<int> Q;
unordered_set<int> v;
void deQ() {
    int s = Q.front();
    Q.pop();
    for (int i = 0 ; i < n ; ++i) {
        b[i] = s & 63;
        s >>= 6;
    }
}
void enQ() {
    int s = 0;
    for (int i = n - 1 ; i >= 0 ; --i) {
        if (a[i] < 0 || a[i] > m[i]) return;
        s <<= 6;
        s |= a[i];
    }
    if (v.find(s) != v.end()) return;
    v.insert(s);
    Q.push(s);
}
main() {
    cin>>n;
    for (int i = 0 ; i < n ; ++i) {
        cin>>m[i];
        mx = max(mx, m[i]);
    }
    cin>>t;
    g = m[0];
    for (int i = 1 ; i < n ; ++i)
        g = __gcd(g, m[i]);
    if (t <= mx && t % g == 0) {
        enQ();
        while (!Q.empty()) {
            ++ans;
            sz = Q.size();
            while (sz--) {
                deQ();
                for (int i = 0 ; i < n ; ++i) {
                    if (b[i] == t) {
                        cout<<ans-1<<"\n";
                        return 0;
                    }
                    a[i] = b[i];
                }
                for (int i = 0 ; i < n ; ++i) {
                    a[i] = m[i];
                    enQ();
                    a[i] = 0;
                    enQ();
                    a[i] = b[i];
                }
                for (int i = 0 ; i < n ; ++i)
                    for (int j = 0 ; j < n ; ++j) {
                        if (i == j) continue;
                        a[i] = max(b[i] + b[j] - m[j], 0);
                        a[j] = min(b[i] + b[j], m[j]);
                        enQ();
                        a[i] = b[i], a[j] = b[j];
                    }
            }
        }
    }
    cout<<"-1\n";
}