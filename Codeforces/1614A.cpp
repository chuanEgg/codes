#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,l,r,k;
        cin>>n>>l>>r>>k;
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        sort(s.begin(), s.end());
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] < l || s[i] > r) continue;
            if(k-s[i] < 0) break;
            k-=s[i];
            cnt++;
        }
        cout << cnt <<"\n";
    }
}