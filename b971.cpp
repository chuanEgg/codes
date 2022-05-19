#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    while(a!=b){
        cout<<a<<" ";
        a+=c;
    }
    cout<<a<<"\n";
}