#include <iostream>
#include "lib0052.h"

using namespace std;

int main(){
    Init();
    int s=1 ,e=1000001;
    while(s!=e-1){//換行邪教
        int k=s+(e-s)/2;
        int rtrn=Query(k);
        if(rtrn){
            s=k;
        }else{
            e=k;
        }
    }
    Answer(s);
    return 0;
}