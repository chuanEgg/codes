#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(a*a > b*b){
        cout << "YP wins!\n";
    }else if(a*a < b*b){
        cout << "BB wins!\n";
    }else{
        cout << "QAQ\n";
    }
}