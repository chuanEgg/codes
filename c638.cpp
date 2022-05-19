#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
string a[] = {"庚","辛","壬","癸","甲","乙","丙","丁","戊","己"};
string b[] = {"申","酉","戌","亥","子","丑","寅","卯","辰","巳","午","未"};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        n-=1800;
        cout<<a[n%10]<<b[n%12]<<"\n";
    }
}