#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double h,l;
    cin>>h>>l;
    cout<<fixed<<setprecision(5)<<(h*h+l*l)/(2*h)<<"\n";
}

//((r-h)^2+l^2)=r^2
