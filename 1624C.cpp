#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> s(n);
        vector<bool> c(n+1,0);
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        sort(s.begin(), s.end(), greater<>());
        bool flag = 1;
        for(auto i:s){
            int temp = i;
            while(temp > n || c[temp]){
                temp /= 2;
            }
            if(temp > 0){
                c[temp] = 1;
            }else{
                flag = 0;
            }
        }
        cout << (flag?"yes\n":"no\n");
    }
}