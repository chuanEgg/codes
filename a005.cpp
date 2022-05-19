#include <iostream>

using namespace std;

int main(){
    int i;
    cin>>i;
    for(int n = 0 ; n<i ; n++) {
        int a,b,c,d,e;
        cin>>a>>b>>c>>d;
        if((b-a)==(c-b)||(c-b)==(d-c)){
            e = d+(b-a);
        }else{
            e = d*(b/a);
        }
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
    }
    return 0;
}