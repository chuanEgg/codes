#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

void f(int x){
    cout<<x<<" ";
    if(x == 1) return;
    if(x%2 ==0){
        f(x/2);
    }else{
        f(3*x+1);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    f(n);
}