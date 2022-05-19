#include <iostream>
#include <set>
#include <string>

using namespace std;

bool flag;
set<string> ms {"H", "HE", "LI", "BE", "B", "C", "N", "O", "F", "NE", "NA", "MG", "AL", "SI", "P", "S", "CL", "AR", "K", "CA", "SC", "TI", "V", "CR", "MN", "FE", "CO", "NI", "CU", "ZN", "GA", "GE", "AS", "SE", "BR", "KR", "RB", "SR", "Y", "ZR", "NB", "MO", "TC", "RU", "RH", "PD", "AG", "CD", "IN", "SN", "SB", "TE", "I", "XE", "CS", "BA", "LA", "CE", "PR", "ND", "PM", "SM", "EU", "GD", "TB", "DY", "HO", "ER", "TM", "YB", "LU", "HF", "TA", "W", "RE", "OS", "IR", "PT", "AU", "HG", "TL", "PB", "BI", "PO", "AT", "RN", "FR", "RA", "AC", "TH", "PA", "U", "NP", "PU", "AM", "CM", "BK", "CF", "ES", "FM", "MD", "NO", "LR", "RF", "DB", "SG", "BH", "HS", "MT", "DS", "RG", "CN", "NH", "FL", "MC", "LV", "TS", "OG"};
void dfs(string s){
    if((s.length()==1 || s.length()==2) && ms.count(s)){
        flag = 1;
    }else{
        if(ms.count(s.substr(0,1)))
            dfs(s.substr(1,(s.length()-1)));
        if(ms.count(s.substr(0,2)))
            dfs(s.substr(2,(s.length()-2)));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    flag = 0;
    string s;
    cin>>s;
    dfs(s);
    cout<<(flag?"YES\n":"NO\n");
}