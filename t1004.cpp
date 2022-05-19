#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k=1;
    cin>>n;
    while(n>=k*2){
        k*=2;
    }
    cout<<(n-k)*2+1<<"\n";
}