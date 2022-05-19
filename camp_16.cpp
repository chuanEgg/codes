#include <iostream>
#include <stack>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    stack<int> stk;
    while(n--){
        int o;
        cin>>o;
        switch (o)
        {
        case 1:
            int temp;
            cin>>temp;
            stk.push(temp);
            break;
        case 2:
            if(stk.empty()){
                cout<<"QQ\n";
            }else{
                stk.pop();
            }
            break;
        case 3:
            if(stk.empty()){
                cout<<"QQ\n";
            }else{
                cout<<stk.top()<<"\n";
            }
            break;
        case 4:
            cout<<stk.size()<<"\n";
            break;
        }
    }
}