#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

const int maxn = 1e6+1;
const int mod = 1e9+7;

int lpf[maxn], s[maxn];
vector<int> prime;
bool flag;

void eratosthenes(){
    for(int i = 2; i<maxn; i++){
        if(lpf[i] == 1){
            prime.push_back(i);
        }
        for(int p:prime){
            if(i*p >= maxn)
                break;
            lpf[i*p] = p;
        }
    }
}
void handle(int p, int cnt){
    if(flag) cout<<" * ";
    else flag = 1;
    cout<<p;
    if(cnt > 1) cout<<"^"<<cnt;
    return;
}
void factorize(int x){
    int cur = 0, cnt = 0;
    while(lpf[x] != 1){
        // cout<<lpf[x]<<"\n";
        if(lpf[x] == cur){
            cnt++;
        }else {
            if(cnt)
                handle(cur,cnt);
            cur = lpf[x];
            cnt = 1;
        }
        x /= lpf[x];
    }
    if(x == cur){
            cnt++;
    }else {
        if(cnt)
            handle(cur,cnt);
        cur = x;
        cnt = 1;
    }
    handle(cur, cnt);
    return;
    // return factor;
}
int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    fill(lpf, lpf+maxn, 1);
    eratosthenes();
    // cout<<prime.size()<<"\n";
    int n;
    while(cin>>n){
        flag = 0;
        factorize(n);
        cout<<"\n";
    }
    return 0;
}