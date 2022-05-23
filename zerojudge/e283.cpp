#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string alp[6];
    alp[0]="0 1 0 1";
    alp[1]="0 1 1 1";
    alp[2]="0 0 1 0";
    alp[3]="1 1 0 1";
    alp[4]="1 0 0 0";
    alp[5]="1 1 0 0";
    unsigned int n;
    while(cin>>n)
    {
        cin.ignore();
        for(int i=0; i<n; i++){
            string s;
            getline(cin,s);
            for(int j=0; j<6; j++)
            {
                if(s==alp[j]) cout<<(char)(j+'A');
            }
        }
        cout<<"\n";
    }
}