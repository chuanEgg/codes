#include <iostream>

using namespace std;

int main(){
    char temp;
    int y=0,t=0,p=0;
    while(cin>>temp){
        if(temp=='Y'||temp=='y'){
            y++;
        }else if(temp=='T'||temp=='t'){
            t++;
        }else if(temp=='P'||temp=='p'){
            p++;
        }
        //cout<<temp<<endl;
    }
    cout<<min(min(y,t),p)<<"\n";
}