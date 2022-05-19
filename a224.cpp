#include <iostream>
#include <string>

using namespace std;

int main(){
    string s,s2;
    bool state=true;
    while(cin>>s) {
        for(int i=s.length()+1;i>0;i--){
            s2[i]=s[s.length()-i];
        }
       if(s.compare(s2)==-1){
           state=false;
       }
       cout<<s.compare(s2)<<endl;
        if(state==false) {
            cout<<"no..."<<endl;
        }else{
            cout<<"yes!"<<endl;
        }
    }
    return 0;
}