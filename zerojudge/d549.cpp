#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>
#define int long long

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c;
    while(cin>>a>>b>>c){
        cout<<fixed<<setprecision(2)<<sqrt(a*a+c*c-b*b)<<"\n";
    }    
}