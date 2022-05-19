#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    char s;
    while(cin>>a>>s>>b)
    switch(s){
        case '+':
        cout<<a+b<<"\n";
        break;
        case '-':
        cout<<a-b<<"\n";
        break;
        case '*':
        cout<<a*b<<"\n";
        break;
        case '/':
        cout<<a/b<<"\n";
        break;
    }
}