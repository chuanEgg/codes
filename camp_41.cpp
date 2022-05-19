#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>k;
    for(long long i=(k+1); i<=2*k; i++){
        unsigned long long temp = (i*k);
        //cout<<temp<<endl;
        if(temp%(i-k)==0){
            long long x=(temp/(i-k));
            cout<<i<<" "<<x<<"\n";
        }
    }
}