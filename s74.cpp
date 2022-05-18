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
        int n;
        cin >> n;
        vector<int> s(n);
        for(int i = 0; i<n; i++){
            cin >> s[i];
        }
        int temp = -1, stat = 1, ans = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == temp)
                continue;
            if(s[i] < temp ^ stat){
                ans += 1;
                stat = !stat;
            }
            temp = s[i];
        }
        if(stat)
            ans--;
        cout << ans <<"\n";
    }
}