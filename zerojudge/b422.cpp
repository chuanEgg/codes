#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin>>m>>n;
    cout<<m<<" "<<n<<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int r,g,b;
            cin>>r>>g>>b;
            int gray = round((double)(r+g+b)/3);
            for(int k=0; k<3; k++) cout<<gray<<" ";
        }
        cout<<"\n";
    }
}