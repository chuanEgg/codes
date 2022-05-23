#include <iostream>
#include <set>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    set<int> s;
    while(n--)
    {
        int o;
        cin>>o;
        int temp;
        switch (o)
        {
        case 1:
            cin>>temp;
            s.insert(temp);
            break;
        case 2:
            cin>>temp;
            if(s.count(temp)){
                s.erase(temp);
            }else{
                cout<<"error\n";
            }
            break;
        case 3:
            cout<<s.size()<<"\n";
            break;
        case 5:
            if(s.size()){
                cout<<*(s.rbegin())<<"\n";
            }else{
                cout<<"error\n";
            }
            break;
        case 4:
            if(s.size()){
                cout<<*(s.begin())<<"\n";
            }else{
                cout<<"error\n";
            }
            break;
        }
    }
}