#include<iostream>
#include<map>
#include<string.h>
#define INF 100001
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k, a[100002], s, e, temp, len, ans_max = 0, ans_min = 0;
    bool state = 0;
    map<int, int> mp;
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++){
        cin >> temp;
        if(temp && !state){
            s = i;
            state = 1;
        }
        if(!temp && state){
            e = i - 1;
            a[s] = a[e] = e - s + 1;
            state = 0;
            mp[e - s + 1]++;
        }
    }
    if(state){
        e = n;
        a[s] = a[e] = e - s + 1;
        mp[e - s + 1]++;
    }
    if(!mp.empty()){
        ans_max += (mp.rbegin() -> first);
        ans_min += (mp.begin() -> first);
    }
    while(k--){
        cin >> temp;
        if(a[temp - 1] && a[temp + 1]){
            mp[a[temp - 1]] == 1? mp.erase(a[temp - 1]): mp[a[temp - 1]]--;
            mp[a[temp + 1]] == 1? mp.erase(a[temp + 1]): mp[a[temp + 1]]--;
            s = temp - a[temp - 1];
            e = temp + a[temp + 1];
            a[temp + 1] = 0, a[temp - 1] = 0;
            len = e - s + 1;
            a[s] = a[e] = len;
            mp[len]++;
        }
        else if(a[temp - 1]){
            mp[a[temp - 1]] == 1? mp.erase(a[temp - 1]): mp[a[temp - 1]]--;
            s = temp - a[temp - 1];
            len = a[s] + 1;
            a[temp - 1] = 0;
            a[s] = a[temp] = len;
            mp[len]++;
        }
        else if(a[temp + 1]){
            mp[a[temp + 1]] == 1? mp.erase(a[temp + 1]): mp[a[temp + 1]]--;
            e = temp + a[temp + 1];
            len = a[e] + 1;
            a[temp + 1] = 0;
            a[e] = a[temp] = len;
            mp[len]++;
        }
        else{
            a[temp] = 1;
            mp[1]++;
        }
        if(!mp.empty()){
            ans_max += (mp.rbegin() -> first);
            ans_min += (mp.begin() -> first);
        }
    }
    cout << ans_max << "\n" << ans_min << "\n";
    return 0;
}