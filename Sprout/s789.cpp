#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> base(1, 1);
vector<int> cut(int n){
    if(n == 1) return base;
    auto a = cut(n/2);
    auto b = cut((n+1)/2);
    for(int &i:a){
        i = i*2;
    }
    for(int &i:b){
        i = i*2-1;
    }
    auto res = a;
    res.insert(res.end(), b.begin(), b.end());
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    auto ans = cut(n);
    for(auto i:ans){
        cout << i <<" ";
    }
    cout << "\n";
}