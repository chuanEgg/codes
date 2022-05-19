#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    short c;
    cin>>c;
    (c%2)?cout<<c/2<<" "<<(c/2)+1<<endl:cout<<c/2<<" "<<(c/2)<<endl;
}