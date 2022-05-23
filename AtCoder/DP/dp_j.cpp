#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

double n, a, b, c, t;
double e[301][301][301];

double E(int a, int b, int c){
    if(!(a||b||c))
        return e[a][b][c] = 0;
    if(a<0 || b<0 || c<0)
        return -1;
    if(e[a][b][c])
        return e[a][b][c];
    double t = a+b+c;
    e[a][b][c] = ((a/t) * (E(a-1,b,c)+1) + (b/t) * (E(a+1,b-1,c)+1) + (c/t) * (E(a,b+1,c-1)+1) + (n/t) -1);
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