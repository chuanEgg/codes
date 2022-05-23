#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    b+=(a*60);
    d+=(c*60);
    int t=d-b;
    if(t<0) t+=1440;
    cout<<(t/60)<<" "<<(t%60)<<"\n";
}