#pragma GCC optimize("Ofast")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

long long compute_hash(string const& s) {
    int p = 26;
    const int m = 1e6 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a') * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

const int maxn = 1e6+7;
vector<string> mp[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0; i<26; i++){
        for(int j1=0; j1<26; j1++){
            for(int j2=0; j2<26; j2++){
                for(int j3=0; j3<26; j3++){
                    for(int j4=0; j4<26; j4++){
                        string s;
                        s += (char)(i+'a');
                        s += (char)(j1+'a');
                        s += (char)(j2+'a');
                        s += (char)(j3+'a');
                        s += (char)(j4+'a');
                        // cout << s <<"\n";
                        int x = compute_hash(s);
                        mp[x].push_back(s);
                        if(mp[x].size() == 3){
                            for(auto w : mp[x]){
                                cout << w <<"\n"; 
                            }
                            cout << x << "\n\n";
                        }
                    }
                }
            }
        }
    }
    
}