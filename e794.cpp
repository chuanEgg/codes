#include <iostream>

using namespace std;

int fs[100];
int f(int i)
{
    if(fs[i]!=0){
        return fs[i];
    }
    fs[i] = f(i-1)+ f(i-2);
    return fs[i];
}
int main()
{
    fs[0]=1;
    fs[1]=1;
    fs[2]=1;
    int n;
    cin>>n;
    cout<<f(n)<<":"<<f(n+1)<<"\n";
}