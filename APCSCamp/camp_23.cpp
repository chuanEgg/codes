#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    deque<int> v;
    while(n--){
        int o;
        cin>>o;
        int temp;
        switch (o)
        {
        case 1:
            cin>>temp;
            v.push_back(temp);
            break;
        case 2:
            cin>>temp;
            v.push_front(temp);
            break;
        case 3:
            if(v.empty()){
                cout<<"error\n";
            }else{
                cout<<v.back()<<"\n";
            }
            break;
        case 4:
            if(v.empty()){
                cout<<"error\n";
            }else{
                cout<<v.front()<<"\n";
            }
            break;
        case 5:
            if(v.empty()){
                cout<<"error\n";
            }else{
                v.pop_back();
            }
            break;
        case 6:
            if(v.empty()){
                cout<<"error\n";
            }else{
                v.pop_front();
            }
            break;
        case 7:
            cout<<v.size()<<"\n";
            break;
        }
    }
}