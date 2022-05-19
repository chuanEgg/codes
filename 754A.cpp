#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int temp = a+b+c;
        temp %= 3;
        if(temp == 0){
            cout<<"0\n";
        }else{
            cout<<"1\n";
        }
    }
}