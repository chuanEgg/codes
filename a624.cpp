#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctype.h>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin>>s){
        int cnt = 0;
        int temp = 0;
        bool b=0,sm=0,a=0;
        int len = s.length();
        for(int i=0; i<len; i++){
            if(isalpha(s[i])){
                if(islower(s[i])){
                    b=1;
                }else{
                    sm=1;
                }
                temp++;
            }else{
                a = 1;
            }
        }
        if(temp >= 8) cnt++;
        if(b&&sm) cnt++;
        if(a&&temp) cnt++;
        if(cnt == 0){
            cout<<"This password is WEAK\n";
        }else if(cnt == 1){
            cout<<"This password is ACCEPTABLE\n";
        }else if(cnt == 2){
            cout<<"This password is GOOD\n";
        }else{
            cout<<"This password is STRONG\n";
        }
    }
}