#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 2e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int i=1; i<maxn; i++){
        if((i%a) == (b%i)){
            cout<<i<<"\n";
            //break;
        }
    }
}