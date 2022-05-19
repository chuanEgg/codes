#include <iostream>
#include <string>

using namespace std;

int main(){
    int i;
    while(cin>>i) {
        for(int a=0 ; a<i ; a++) {
            string str;
            cin>>str;
            cout<<str;
            int s=1;
            for(int b=0 ; b<str.length() ; b++) {
                s =s+str[b];
                cout<<str[b]<<endl;
                cout<<s<<endl;
            }
            cout<<s<<endl;
        }
    }
    return 0;
}