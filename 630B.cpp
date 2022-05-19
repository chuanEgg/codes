#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double n,t;
    cin>>n>>t;
    cout<<fixed<<setprecision(20)<<n*pow(1.000000011,t);

}