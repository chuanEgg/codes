#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,m;
    cin>>a>>b>>m;
    int d = __gcd(a,b);
    if(m%a == 0||m%b == 0){
        cout<<"YES\n";
    }else
    if(m%d == 0 && (a<=m && b<=m)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}