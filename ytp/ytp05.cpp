#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n,m;
    long long ans=1;
    int a=min(n,m);
    for(int i=1; i<a; i++){
        int x=(2*n+1);
        int y=1;
        while(x>0){
            ans+=x*y;
            x-=2;
            y++;
        }
    }
    for(int i=0; i<a; i+=2){
        int x=(2*n-1);
        int y=2;
        while(x>0){
            ans+=x*y;
            x-=2;
            y++;
        }
    }
    ans+=a;
    
}