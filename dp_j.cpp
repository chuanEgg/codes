#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

double n, a, b, c;
double e[301][301][301];

double E(int a, int b, int c){
    if(!(a||b||c))
        return e[a][b][c] = 0;
    if(e[a][b][c])
        return e[a][b][c];
    int t = a+b+c;
    if(a>0) e[a][b][c] += (1.0*a/t) * (E(a-1,b,c)+1);
    if(b>0) e[a][b][c] += (1.0*b/t) * (E(a+1,b-1,c)+1);
    if(c>0) e[a][b][c] += (1.0*c/t) * (E(a,b+1,c-1)+1);
    e[a][b][c] += (1.0*n/t) -1;
    //cout<<e[a][b][c]<<"\n";
    return e[a][b][c];
}
int main(){
    cin>>n;
    a = b = c = 0;
    memset(e,0,sizeof(e));
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        if(temp==1)
            a++;
        if(temp==2)
            b++;
        if(temp==3)
            c++;
    }
    //cout<<a<<" "<<b<<" "<<c<<"\n";
    cout<<fixed<<setprecision(10)<<E(a,b,c)<<"\n";
}