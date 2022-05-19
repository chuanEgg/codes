#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    for(int i=0; i<m; i++){
        int cmd;
        cin>>cmd;
        if(cmd){
            int a,b;
            bool flag = true;
            cin>>a>>b;
            a--;
            string s = str.substr(a,(b-a));
            //cout<<s<<"\n";
            for (int i=0; i<s.size()/2; i++){
                if (s[i] != s[s.size()-1-i]){
                    flag = 0;
                }
                //cout<<s[i]<<" "<<s[s.size()-1-i]<<"\n";
            }

            if(flag){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }  
        }else{
            int a;
            char b;
            cin>>a>>b;
            str[--a] = b;
            //cout<<str<<"\n";
        }
    }
}