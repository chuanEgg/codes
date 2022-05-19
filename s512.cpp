#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    stack<int> st;
    for(int i=0; i<n; i++){
        if(s[i] < 0){
            if(!st.empty() && st.top() == -s[i]){
                st.pop();
            }else{
                cout << "lose light light\n";
                return 0;
            }
        }
        else{
            st.push(s[i]);
        }
    }
    cout << (st.empty()?"weed\n":"lose light light\n");
}