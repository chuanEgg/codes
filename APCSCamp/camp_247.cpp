#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    stack<long long int> num;
    string temp[n];
    int i=0;
    for(;i<n;i++){
        cin>>temp[i];
    }
    i--;
    long long int result;
    while(i>=0)
    {
        if(temp[i]=="f"){
            long long int x=num.top();
            num.pop();
            result=(2*x-3);
            while(result<0){
                result+=998244353;
            }
            num.push(result%998244353);
        }else if(temp[i]=="g"){
            long long int x=num.top(); num.pop();
            long long int y=num.top(); num.pop();
            result=((2*x)+y-7);
            while(result<0){
                result+=998244353;
            }
            num.push(result%998244353);
        }else if(temp[i]=="h"){
            long long int x=num.top(); num.pop();
            long long int y=num.top(); num.pop();
            long long int z=num.top(); num.pop();
            result=((3*x)-(2*y)+z);
            while(result<0){
                result+=998244353;
            }
            num.push(result%998244353);
        }else {
            num.push(stoll(temp[i]));
        }
        i--;
    }
    cout<<num.top()<<"\n";
}