#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='?')
            {
                if(i==0) s[i]='0';
                else if(i==s.size()-1) s[i]='1';
                else if(s[i-1]=='0' && (s[i+1]=='0' || s[i+1]=='?')) s[i]='0';
                else if(s[i-1]=='1' && (s[i+1]=='1' || s[i+1]=='?')) s[i]='1';
                else s[i]='1';
            }
        }

        cout << s << '\n' ;
    }

    return 0;
}
