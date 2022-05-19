#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int j[3];
    for(int a=0 ; a<3 ; a++) {
        cin>>j[a];
    }
    sort(j,j+3);
    cout<<j[2];
    cout<<endl;
    return 0;
}//我也想用sort阿