#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(b-a == c-b || (a==b && b ==c)){
            cout << "YES\n";
        }else if((2*b-c)%a == 0 && (2*b-c) > 0){
            cout <<"yes\n";
        }else if((2*b-a)%c == 0 && (2*b-a) > 0){
            cout <<"yes\n";
        }else if((a+c)%(2*b) == 0){
            cout <<"yes\n";
        }else{
            cout <<"no\n";
        }
    }
}