#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int m,n,p,s;
    cin>>m>>n>>p;
    int j[n][p][2];
    for(int a=0 ; a<n ; a++) {
        for(int b=0 ; b<p ; b++) {
            cin>>j[a][b][0]>>j[a][b][1];
        }
    }
    return 0;
}