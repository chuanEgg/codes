#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long long a,b;
    cin>>a>>b;
    int sum = 0;
    for(int n=a; n<=b; n++){
        int p=n;
        //cout<<n<<"\n";
        int k = sqrt(n)+1;
        for(int i=1; i<k; i++){
            if(n/i*i == n){
                p-=i;
                if(i>1&&i!=(n/i)){
                    p-=(n/i);
                }
                //cout<<i<<"\t"<<(n/i)<<"\n";
            } 
        } 
        sum+=p;
        while(sum<0){
            sum+=1e9+7;
        }
        sum%=((long long)1e9+7);
    }
    
    cout<<sum<<"\n";
}