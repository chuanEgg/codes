#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a,b,c,d;
    while(cin>>a>>b>>c>>d&&(a||b||c||d))
    {
        a*=60;
        c*=60;
        b+=a;
        d+=c;
        //cout<<b<<endl<<d<<endl;
        int t=d-b;
        (t>=0)?cout<<t<<"\n":cout<<1440+t<<"\n";
    }
}