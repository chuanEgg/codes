#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int ind = 0, ans = 0;
string str;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    int len = str.length(), cnt = 1;
    while (ind + cnt - 1 < len >> 1) {
        if (str.substr(ind, cnt) == str.substr(len - ind - cnt, cnt)) {
            // cout << ind << ' ' << str.substr(ind, cnt) << '\n';
            ans += 2;
            ind += cnt;
            cnt = 1;
        }
        else ++cnt;
    }
    if (ans == 0) ans = 1;
    else if (len & 1) ++ans;
    cout << ans << '\n';
}
//!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]_̂`abcdefghijklmnopqrstuvwxyz{|}