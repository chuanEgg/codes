#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int calculate(string s) {
    int temp= 0, num= 0, sign= 1, n= s.size();
    stack<int> stk;
    for (int  i= 0; i< n; i++) {
        char ch = s[i];
        if(ch >= '0') {
            num = 10 * num + (ch - '0');
        }else if(ch == '+' || ch == '-') {
            temp += sign * num;
            num = 0;
            sign = (ch == '+')?1: -1;
        }else if(ch == '(') {
            stk.push(temp);
            stk.push(sign);
            temp = 0;
            sign = 1;
        }else if(ch == ')') {
            temp += sign * num;
            num = 0;
            temp *= stk.top();
            stk.pop();
            temp += stk.top();
            stk.pop();
        }
    }
    temp += sign * num;
    return temp;
}
int main() 
{ 
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin,s);
    cout<<calculate(s)<<"\n";
    
    return 0; 
} 