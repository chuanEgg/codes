#include <bits/stdc++.h>

using namespace std;
const int maxn = 1505;
int cnt[maxn];

void initialize(int n){
    memset(cnt, 0, sizeof(cnt));
}
int hasEdge(int a, int b){
    ++cnt[max(a,b)];
    return cnt[max(a,b)] == max(a,b);
}
//Sam 說：要慢慢想Game，於是我就想到了Game