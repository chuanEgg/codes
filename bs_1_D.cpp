#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << upper_bound(s.begin(), s.end(), r) - lower_bound(s.begin(), s.end(), l)<<" ";
    }
}