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
        int n, m, mx = 0;
        cin >> n >> m;
        vector<int> s(n);
        for(int i=0; i<n; i++){
            cin >> s[i];
            mx = max(mx, s[i]);
        }
        int l = mx, r = 1e9+5;
        while(l < r){
            int mid = l+(r-l)/2;
            int res = 1, temp = 0;
            for(int i = 0; i<n; i++){
                if(temp + s[i] > mid){
                    res++;
                    temp = s[i];
                }else{
                    temp += s[i];
                }
            }
            // cout << mid <<'\t' << res <<"\n";
            if(res <= m){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        cout<<l<<"\n";
    }
}