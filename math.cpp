#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

double cal(int x, int y){
    return ((x*1.0/(x+y*1.0)) * ((x-1.0)/(x+y-1.0)));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int x=0; x<=50000; x++){
        for(int y=0; y<=50000; y++){
            // cout<<cal(x,y)<<"\n";
            if(cal(x,y) == 0.5){
                cout<<x<<" "<<y<<"\n";
            }
        }
    }
}