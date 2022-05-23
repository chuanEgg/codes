#include <iostream>
#include <stack>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string n;
    stack<char> stk;
    cin>>n;
    stk.push(n[0]);
    for(int i=1; i<n.length(); i++)
    {
        if(!stk.empty()&&stk.top()==n[i]){
            stk.pop();
        }else{
            stk.push(n[i]);
        }
    }
    int sze= stk.size();
    char arr[sze];
    for(int i=sze-1; i>=0; i--)
    {
        arr[i]=stk.top();
        stk.pop();
    }
    for(int i=0; i<sze; i++){
        cout<<arr[i];
    }
    cout<<"\n";
}