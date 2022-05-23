#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int i,s;
    while(cin>>i){
        int j[i];
        for(int a=0 ; a<i ; a++) {
            cin>>j[a];
        }
        sort(j,j+i);
        for(int a=0 ; a<i ; a++) {
            cout<<j[a]<<" ";
        }
        cout<<endl;
    }
    return 0;
}