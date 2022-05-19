#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        unsigned long long int ans[n] = {0};
        ans[0] = 3;
        ans[1] = 7;
        for(int i = 2 ; i < n ; i++){
            unsigned long long int k = (2*ans[(i-1)]) + ans[(i-2)];
            ans[i] = k;
            if(i == (n-1)){
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}