#include <iostream>
#include <string>

using namespace std;

string cut(string s){
    if(s.length()%2==1) return s;
    string temp1 = s.substr(0, s.length()/2);
    string temp2 = s.substr(s.length()/2, s.length()/2);
    temp1 = cut(temp1);
    temp2 = cut(temp2);
    if(temp1 < temp2) return temp1+temp2;//照字典序排
    return temp2+temp1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,u;
    cin>>s>>u;
    s = cut(s);//與s等價的最小字典序的字串
    u = cut(u);
    cout<<((s==u)?"YES":"NO")<<"\n";
}