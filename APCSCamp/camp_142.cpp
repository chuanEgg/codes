#include <iostream>

using namespace std;

int n,m,k;

int bruh(int t, int k){
    if(k==1) return m%t;
    return (bruh(t-1, k-1)+m%t)%t;//re
}
int main(){
    cin>>n>>m>>k;
    cout<<bruh(n,k)+1<<"\n";
}