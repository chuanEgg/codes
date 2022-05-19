#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    unsigned long long int n, t;
    bool prime;
    t == 1;
    
    while(cin >> n){
    prime= 1;
    if(n== 1) cout << "no\n";
    else if(n== 2) cout << "yes\n";
    else{
        int k= sqrt(n)+ 1;
        for(int i= 2; i<= k; i++){
            if(n%i== 0){
                cout<<"no\n";
                prime= 0;
                break;
            }
        }
        if(prime) cout << "yes\n";
    }
    }
    return 0;
}