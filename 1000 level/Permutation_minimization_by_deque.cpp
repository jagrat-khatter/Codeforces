#include<bits/stdc++.h>
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        string t= "";
        ll fst ;
        deque<ll> dq;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            if(i==0) {dq.push_back(x) ; fst = x;}
            else if(x>fst) {dq.push_back(x) ;}
            else if(x<fst) {dq.push_front(x) ; fst = x;}
        }

        for(auto &i : dq) cout << i <<  ' ';

        cout << t << '\n' ;

    }
    return 0;
}