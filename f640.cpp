#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string s,in;
    getline(cin,in);
    stringstream ss;
    ss<<in;
    stack<int> num;
    vector<string> temp;
    int sum=0;
    while(ss>>s){
        temp.push_back(s);
    }
    int i=temp.size()-1;
    while(i>=0)
    {
        if(temp[i]==" "){
            continue;
        }else if(temp[i]=="f"){
            int x=num.top();
            num.pop();
            num.push(2*x-3);
        }else if(temp[i]=="g"){
            int x=num.top(); num.pop();
            int y=num.top(); num.pop();
            num.push((2*x)+y-7);
        }else if(temp[i]=="h"){
            int x=num.top(); num.pop();
            int y=num.top(); num.pop();
            int z=num.top(); num.pop();
            num.push((3*x)-(2*y)+z);
        }else {
            num.push(stoi(temp[i]));
        }
        i--;
    }
    cout<<num.top()<<endl;
}