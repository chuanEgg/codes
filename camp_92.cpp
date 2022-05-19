#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> m;
    int cnt=1;
    for(int i=0; i<26; i++){
        string temp;
        temp += (char)('a'+i);
        m[temp] = cnt++;
        //cout<<("a"+i);
       // cout<<temp<<" "<<cnt<<"\n";
    }
    for(int i=0; i<26; i++){
        for(int j=i+1; j<26; j++){
            string temp;
            temp += (char)('a'+i);
            temp += (char)('a'+j);
            m[temp] = cnt++;
           // cout<<temp<<" "<<cnt<<"\n";
        }
    }
    for(int i=0; i<26; i++){
        for(int j=i+1; j<26; j++){
            for(int k=j+1; k<26; k++){
                string temp;
                temp += (char)('a'+i);
                temp += (char)('a'+j);
                temp += (char)('a'+k);
                m[temp] = cnt++;
              //  cout<<temp<<" "<<cnt<<"\n";
            }
        }
    }
    for(int i=0; i<26; i++){
        for(int j=i+1; j<26; j++){
            for(int k=j+1; k<26; k++){
                for(int l=k+1; l<26; l++){
                    string temp;
                    temp += (char)('a'+i);
                    temp += (char)('a'+j);
                    temp += (char)('a'+k);
                    temp += (char)('a'+l);
                    m[temp] = cnt++;
                   // cout<<temp<<" "<<cnt<<"\n";
                }
            }
        }
    }
    for(int i=0; i<26; i++){
        for(int j=i+1; j<26; j++){
            for(int k=j+1; k<26; k++){
                for(int l=k+1; l<26; l++){
                    for(int o=l+1; o<26; o++){
                        string temp;
                        temp += (char)('a'+i);
                        temp += (char)('a'+j);
                        temp += (char)('a'+k);
                        temp += (char)('a'+l);
                        temp += (char)('a'+o);
                        m[temp] = cnt++;
                        //cout<<temp<<" "<<cnt<<"\n";
                    }
                }
            }
        }
    }
    int n;
    cin>>n;
    while(n--)
    {
        string temp;
        cin>>temp;
        cout<<m[temp]<<"\n";
    }
}

//Brainless Solution Provided by Muen
//Improved