#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int ans, n;
string s;
int pos;
int solve(int layer){
    pos ++;
    if(s[pos] == '2'){
        //cout<<layer<<"\n";
        return solve(layer+1)+solve(layer+1)+solve(layer+1)+solve(layer+1);
    }else if(s[pos] == '1'){
        return pow(n/pow(2,layer),2);
    }else   return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    cin>>n;
    pos = -1;
    cout<<solve(0)<<"\n";
}