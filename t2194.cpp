#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    vector<int> t(n-1), s(n), d(n);
    for(int i=0; i<n-1; i++)
        cin >> t[i];
    for(int i=0; i<n; i++)
        cin >> s[i];
    for(int i=0; i<n; i++)
        cin >> d[i];
}