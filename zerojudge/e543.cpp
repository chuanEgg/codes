#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<char,char> m;
    m['A']='A';
    m['E']='3';
    m['H']='H';
    m['I']='I';
    m['L']='J';
    m['J']='L';
    m['M']='M';
    m['O']='O';
    m['T']='T';
    m['U']='U';
    m['V']='V';
    m['W']='W';
    m['X']='X';
    m['Y']='Y';
    m['Z']='5';
    m['S']='2';
    m['1']='1';
    m['2']='S';
    m['3']='E';
    m['5']='Z';
    m['8']='8';
    string n;
    while(cin >> n)
    {
        //cout<<n<<endl;
        string rev;
        int j=0;
        for(int i=n.length()-1; i>=0; i--)
        {
            rev+=n[i];
        }
        //cout<<rev<<endl;
        string mirror;
        for(int i=0; i<n.length(); i++)
        {
            if(m.count(n[i]))
            {
                mirror+=m[n[i]];
            }else{
                mirror+=n[i];
            }
        }
        //cout<<mirror<<endl;
        bool isRev=1, isMir=1;
        for(int i=0; i<n.length(); i++)
        {
            if(rev[i]!= n[i])
            {
                isRev =0;
            }
            if(mirror[i]!= rev[i])
            {
                isMir =0;
            }
            if(!(isMir||isRev)) break;
        }
        
        if(isMir&&isRev)
        {
            cout<< n <<" -- is a mirrored palindrome.\n";
        }else if(isMir)
        {
            cout<< n <<" -- is a mirrored string.\n";
        }else if(isRev)
        {
            cout<< n <<" -- is a regular palindrome.\n";
        }else{
            cout<< n <<" -- is not a palindrome.\n";
        }
    }
}