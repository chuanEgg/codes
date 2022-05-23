#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e6+5;
int bucket[maxn]{0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        memset(bucket, 0, sizeof(bucket));
        int n, m;
        cin >> n >> m;
        vector<int> s(n), f(m), num;
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        for(int i=0; i<m; i++){
            cin >> f[i];
            if(!bucket[f[i]])
                num.push_back(f[i]);
            bucket[f[i]]++;
        }
        int ans = 0, k = 0;
        sort(num.begin(), num.end());
        sort(s.begin(), s.end());
        num.push_back(1e6);
        // for(int i=0; i<m;i++){
        //     cout << num[i] <<" ";
        // }cout <<"\n";
        for(int i =0; i<num.size()-1; i++){
            for(int j=0; j<n; j++){
                int temp = min((s[j]%num[i+1])/num[i], bucket[num[i]]);
                s[j] -= temp*num[i];
                bucket[num[i]] -= temp;
                ans += temp;
            }
            for(int j=0; j<n; j++){
                int temp = min(s[j]/num[i], bucket[num[i]]);
                s[j] -= temp*num[i];
                bucket[num[i]] -= temp;
                ans += temp;
            }
        }
        cout << ans <<"\n";
    }
}