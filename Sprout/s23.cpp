#include <stack>

using namespace std;
const int maxn = 5e3+5;
bool instack[maxn][2];

void solve(int N, int order[]){
    stack<int> st[2];
    int cur = 0;
    for(int i=0; i<N; i++){
        push_train();
        st[0].push(i);
        while(!st[0].empty() && order[cur] == st[0].top()){
            move_station_1_to_2();
            pop_train();
            cur++;
            st[0].pop();
        }
    }
    int rnd = 0;
    while(cur < N){
        while(!st[rnd].empty()){
            int temp = st[rnd].top();
            if(temp == order[cur]){
                if(!rnd){
                    move_station_1_to_2();
                    pop_train();
                    cur++;
                }else{
                    pop_train();
                    cur++;
                }
            }else{
                if(!rnd){
                    move_station_1_to_2();
                }else{
                    move_station_2_to_1();
                }
                st[!rnd].push(temp);
            }
        }
        rnd != rnd;
    }
}