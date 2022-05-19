#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1e6+5;
int num[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        num[s[i]]++;
    }
    for(int i=maxn; i>0; i--){
        int div = 0;
        for(int j=i; j<maxn; j+=i){
            div+=num[j];
        }
        if(div >= 2){
            cout<<i<<"\n";
            break;
        }
    }
}