#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    stack<int> st;
    while(t--){
        int o, n;
        cin >> o;
        if(o == 1){
            cin >> n;
            st.push(n);
        }else{
            if(st.empty()){
                cout << "empty!\n";
            }else{
                cout << st.top() <<"\n";
                st.pop();
            }
        }
    }
}