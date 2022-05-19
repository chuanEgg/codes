#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string, int> s;
int main(){
    int n1 = 1;
    for(int i = 0; i < 26; i++){
        string ss = (char)'a' + i;
        s[ss] = n1;
        n1++
    }
    for(int i = 0; i < 26; i++){
        string ss = (char)'a' + i;
        for(int j = i + 1; j < 26; j++){
            ss += (char)'a' + j;
            s[ss] = n1;
            ss.pop_back();
            n1++;
        }
    }
    for(int i = 0; i < 26; i++){
        string ss = (char)'a' + i;
        for(int j = i + 1; j < 26; j++){
            ss += (char)'a' + j;
            for(int k = j + 1; k < 26; k++){
                ss += (char)'a' + k;
                s[ss] = n1;
                ss.pop_back();
                n1++;
            }
            ss.pop_back();
        }
    }
    for(int i = 0; i < 26; i++){
        string ss = (char)'a' + i;
        for(int j = i + 1; j < 26; j++){
            ss += (char)'a' + j;
            for(int k = j + 1; k < 26; k++){
                ss += (char)'a' + k;
                for(int l = k + 1; l < 26; l++){
                    ss += (char)'a' + l;
                    s[ss] = n1;
                    ss.pop_back();
                    n1++;
                }
            }
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = i + 1; j < 26; j++){
            for(int k = j + 1; k < 26; k++){
                for(int l = k + 1; l < 26; l++){
                    for(int m = l + 1; m < 26; m++){
                        s.insert((string)('a' + i) + (string)('a' + j) + (string)('a' + k) + (string)('a' + l) + (string)('a' + m));
                    }
                
                }
            }
        }
    }
    int n;
    cin >> n;
    string str;
    while(n--){
        cin >> str;
        cout << s.find(str) << "\n";
    }
}