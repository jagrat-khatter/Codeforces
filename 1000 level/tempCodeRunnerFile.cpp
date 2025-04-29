#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
string func(ll n)
{
    string t = "";
    while(n)
    {
        ll r = n%10;
        n = n/10;
        char p = (char)(48+r);
        t = t + p;
    }
    reverse(t.begin() , t.end());

    return t;
}
signed main()
{
    ios::sync_with_stdio;
    cin.tie(NULL);

    string ans = func(9812);
    cout << ans ;
    
    return 0;
}
