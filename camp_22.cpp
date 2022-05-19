#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

map<char, int> oper
{ 
    {'*', 2}, {'/', 2}, {'%', 2},
    {'+', 1}, {'-', 1},
};
int priority(char c) 
{ 
    return oper.find(c) != oper.end()?oper[c]:-1;
}
vector<string> trans(string s) 
{ 
    stack<char> st; 
    vector<string> result;
    for(int i = 0; i < s.size(); i++) 
    {  
        if(s[i] >= '0' && s[i] <= '9'){
            string num;
            while(s[i] >= '0' && s[i] <= '9'){
                num += s[i++];
            }
            i--;
            result.push_back(num); 
        }
        else if(s[i] == ' '){
            continue;
        }
        else if(s[i] == '('){
            st.push('(');
        }
        else if(s[i] == ')') 
        { 
            while(!st.empty() && st.top() != '(') 
            { 
                result.push_back(string(1,st.top())); 
                st.pop();
            } 
            st.pop();
        }else{ 
            while(!st.empty() && priority(s[i]) <= priority(st.top()))
            { 
                result.push_back(string(1,st.top())); 
                st.pop();
            } 
            st.push(s[i]); 
        } 
  
    } 
    while(!st.empty()) 
    { 
        result.push_back(string(1,st.top())); 
        st.pop();
    } 
    return result;
  
} 


int calcu(int x, int y, string op){
    if(op=="+"){
        return x+y;
    }
    if(op=="-"){
        return x-y;
    }
    if(op=="*"){
        return x*y;
    }
    if(op=="/"){
        return x/y;
    }
    if(op=="%"){
        return x%y;
    }
    return 0;
}
int calcufinal(vector<string>& ss) {
    stack<int> calcuStack;
    for(string s: ss){
        if(s.size()==1 && oper.find(s[0])!=oper.end()){
            int x = calcuStack.top();
            calcuStack.pop();
            int y = calcuStack.top();        
            calcuStack.pop();
            calcuStack.push(calcu(y, x, s));
        }
        else{
            calcuStack.push(atoi(s.c_str()));
        }
    }
    return calcuStack.top();
}

int main() 
{ 
    string in;
    while(getline(cin,in)){
        vector<string> v = trans(in);
        cout << calcufinal(v) << endl;
    }
    return 0; 
} 