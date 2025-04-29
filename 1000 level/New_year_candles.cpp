#include <bits/stdc++.h>
using namespace std;
using ll =long long;
ll max(ll a , ll b)
{
    if(a>b) return a;
    else return b;
}
ll min(ll a , ll b)
{
    if(a>b) return b;
    else return a;
}
ll func(ll x , ll m)       // this will how much time the child will ask for candy
{
    ll ct= (x + m -1) / m;
    return ct;
}
using ll = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    string s; cin >> s;
    vector<ll> v(27 , 0) ;       // we'll be using one based indexing
        for(ll i=0;i<s.size();i++)
        {
            ll n = (int)(s[i])  -97 +1;
            v[n]++;
        }

    for(ll i=1;i<=26;i++) cout << v[i] << ' ';

    return 0;
}   
