#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int n, d;
double l = 0, r = 101, ll, rr;
vector<int> s;

int get_ans(double m){
    ll = rr = -1;
    vector<double> pref(n+1,0);
    double mn = 105;
    for(int i=0; i<n; i++){
        pref[i+1] = pref[i]+s[i]-m;
        // cout << pref[i+1]<<(" \n"[i == n-1]);
        if(i-d+1 >= 0){
            if(pref[i-d+1] < mn){
                mn = pref[i-d+1];
                ll = i-d+1;
            }
            if(pref[i+1]-mn >= 0){
                rr = i;
                break;
            }
        }
    }
    // cout << m<<"\t"<<ll<<"\t"<<rr<<"\t"<<l<<"\t"<<r<<"\n";
    if(ll != -1 && rr != -1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    s.resize(n);
    for(int i=0; i<n; i++){
        cin >>s[i];
    }
    for(int i=0; i<100; i++){
        double m = (l+r)/2;
        if(get_ans(m)){
            l = m;
        }else{
            r = m;
        }
    }
    get_ans(l);
    cout << ll+1 <<" "<<rr+1<<"\n";
}