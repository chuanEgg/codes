#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
int n, h[100000], p[100000], num, tmp, root;
long long ans;
vector <int> v[100000];
 
void func(int num){
    if (v[num].empty()){
        h[num] = 0;
    }else{
        int mx = 0;
        for (int i:v[num]){
            func(i);
            mx = max(mx, h[i]+1);
        }
        h[num] = mx;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n){
        memset(p, -1, sizeof(p));
        for (int i = 0; i < n; i++){
            v[i].clear();
            cin >> num;
            for (int j = 0; j < num; j++){
                cin >> tmp;
                // 轉換成zero-based
                tmp--;
                v[i].push_back(tmp);
                p[tmp] = i;
            }
        }
        for (int i = 0; i < n; i++){
            if (p[i] == -1){
                root = i;
                break;
            }
        }
        func(root);
        ans = 0;
        for (int i = 0; i < n; i++){
            ans += h[i];
        }
        cout << root+1 << "\n" << ans << "\n";
    }
}