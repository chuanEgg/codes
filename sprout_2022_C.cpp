#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> m[10], p[10], s[10], z[10];
//1 horizontal
//0 vertical

void push(string str, int stat, int idx){
    int pos = (str[0]-'0');
    if(str[1] == 'm'){
        m[pos].insert(m[pos].begin()+idx, stat);
    }else if(str[1] == 'p'){
        p[pos].insert(p[pos].begin()+idx, stat);
    }else if(str[1] == 's'){
        s[pos].insert(s[pos].begin()+idx, stat);
    }else{
        z[pos].insert(z[pos].begin()+idx, stat);
    }
}
void del(string str){
    int pos = (str[0]-'0');
    if(str[1] == 'm'){
        m[pos].pop_back();
    }else if(str[1] == 'p'){
        p[pos].pop_back();
    }else if(str[1] == 's'){
        s[pos].pop_back();
    }else{
        z[pos].pop_back();
    }
}
void insert(string c1, string c2){
    push(c1,0,0);
    del(c2);
}
void pon(string c1, string p1, string c2){
    if(p1 == "left"){
        push(c1,1,0);
    }else if(p1 == "opposite"){
        push(c1,1,1);
    }else{
        push(c1,1,2);
    }
    del(c2);
}
void chi(string c1, string c2, string c3, string c4){
    push(c1,1,0);
    del(c4);
}
void out(){
    vector<char> ans_c;
    for(int i=1; i<=9; i++){
        //cout<<i<<"\n";
        for(auto j:m[i]){
            if(j == 0){
                cout<<i;
                ans_c.push_back('m');
            }else{
                cout<<"..";
                ans_c.push_back((char)(i+'0'));
                ans_c.push_back('m');
            }
        }
    }
    for(int i=1; i<=9; i++){
        for(auto j:p[i]){
            if(j == 0){
                cout<<i;
                ans_c.push_back('p');
            }else{
                cout<<"..";
                ans_c.push_back((char)(i+'0'));
                ans_c.push_back('p');
            }
        }
    }
    for(int i=1; i<=9; i++){
        for(auto j:s[i]){
            if(j == 0){
                cout<<i;
                ans_c.push_back('s');
            }else{
                cout<<"..";
                ans_c.push_back((char)(i+'0'));
                ans_c.push_back('s');
            }
        }
    }
    //cout<<"s done\n";
    for(int i=1; i<=9; i++){
        for(auto j:z[i]){
            if(j == 0){
                cout<<i;
                ans_c.push_back('z');
            }else{
                cout<<"..";
                ans_c.push_back((char)(i+'0'));
                ans_c.push_back('z');
            }
        }
    }
    //cout<<"hi\n";
    cout<<"\n";
    for(auto i:ans_c){
        cout<<i;
    }
    cout<<"\n";
    //cout<<"q done\n";
    //debug();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=0; i<10; i++){
            m[i].clear();
            p[i].clear();
            s[i].clear();
            z[i].clear();
        }
        string in;
        for(int i=0; i<13; i++){
            cin>>in;
            push(in,0,0);
            //cout<<i<<"\n";
        }
        // cout<<"pass\n";
        out();
        int q;
        cin>>q;
        while(q--){
            string op;
            cin>>op;
            if(op == "insert"){
                string c1, c2 ,trash;
                cin>> c1>> trash>> c2;
                insert(c1,c2);
            }else if(op == "pon"){
                string c1, p1, c2, trash1, trash2;
                cin>> c1>> trash1>> p1>> trash2>> c2;
                pon(c1,p1,c2);
            }else{
                string c1, c2, c3, c4, trash1, trash2, trash3;
                cin>> c1>> trash1>> c2>> trash2>> c3>> trash3>> c4;
                chi(c1,c2,c3,c4);
            }
            out();
        }  
            
    }
}
