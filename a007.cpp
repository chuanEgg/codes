#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool a[46342];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    vector <int> v;
    for (int j = 2; j < 46342; j++){
        if (!a[j]){
            v.push_back(j);
            for (int i = j * j; i < 46342; i += j){
                a[i] = true;
            }
        }
    }
    while (cin >> n){
        if (n > 46341){
            m = sqrt(n);
            bool flag = true;
            for (int i:v){
                if (n % i == 0){
                    flag = false;
                    cout << "非質數\n";
                    break;
                }
            }
            if (flag) cout << "質數\n";
        }else{
            if (a[n]) cout << "非質數\n";
            else cout << "質數\n";
        }
    }
    return 0;
}