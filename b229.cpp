#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int n=0;
    while(cin>>n){
        unsigned long long int ans = 0;
        int s[3] = {0,2,3};
        int x = pow(3,n);
       
        int a[n][x] = {0};
       
        for(int i = 0 ; i < n ; i++){
            for(int k = 0 ; k < x ; k++){
                int y = pow(3,i);
                int j = (int(k/y)) % 3;
                a[i][k] = s[j];
            }
        }
        int k = 0;
        int num  = 0 ;
        for(int i = 0 ; i < x ; i++){
            for(int k = 1 ; k < n ; k++){
                num = 0;
                if(a[k][i]-a[k-1][i] == 1){
                    num += 1 ;
                    cout<<num<<endl;
                }
            }
            k = num;
            if(k == 0){
                ans += 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}