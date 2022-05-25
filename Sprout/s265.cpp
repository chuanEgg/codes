#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int p[] = {97, 101}, maxlen = 5e5+5;
const long long q[] = {1000000007, 1000000009};
long long shash[maxlen][2]{0}, thash[maxlen][2]{0};
long long res_pow[maxlen][2];

long long fastpow(long long x, long long t, long long q){
    long long res = 1;
    while(t > 0){
        if(t & 1)
            res = res*x % q;
        x = x*x % q;
        t>>=1;
    }
    return res % q;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    for(int i=0; i<max(s.length(), t.length()); i++){
        for(int j=0; j<2; j++){
            if(!i) res_pow[i][j] = 1;
            else
            res_pow[i][j] = (res_pow[i-1][j]*p[j]) % q[j];
        }
    }
    for(int i=0; i<s.length(); i++){
        for(int j=0; j<2; j++){
            if(!i) shash[i][j] = s[i]-'a';
            else{
                shash[i][j] = shash[i-1][j] + ((s[i]-'a')*res_pow[i][j])%q[j];
                shash[i][j] %= q[j];
            }
        }
    }
    for(int i=0; i<t.length(); i++){
        for(int j=0; j<2; j++){
            if(!i) thash[i][j] = t[i]-'a';
            else{
                thash[i][j] = thash[i-1][j] + ((t[i]-'a')*res_pow[i][j])%q[j];
                thash[i][j] %= q[j];
            }
        }
    }
    vector<int> ans;
    for(int i=0; i+s.length()-1 < t.length(); i++){
        bool flag = 1;
        for(int j=0; j<2; j++){
            long long temp = (!i ? thash[s.length()-1][j] : thash[i+s.length()-1][j] - thash[i-1][j] + q[j]) % q[j];
            temp = temp*(fastpow(res_pow[i][j] % q[j], q[j]-2, q[j])) % q[j];
            if(temp != shash[s.length()-1][j]){
                flag = 0;
                break;
            }
        }
        if(flag)    ans.push_back(i);
    }
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] <<(" \n"[i == ans.size()-1]);
    
}
// a/b mod p = ab^(p-2) mod p