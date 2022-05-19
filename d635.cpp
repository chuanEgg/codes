#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n && n>=0){
        cout<<oct<<n<<"\n";
    }
    cout<<"-1\n";
}