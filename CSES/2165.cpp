#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void f(int n,int a, int b, int c){
    if(!n) return;
    f(n-1,a,c,b);
    cout<<a<<" "<<c<<"\n";
    f(n-1, b,a,c);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    f(n,1,2,3);
}