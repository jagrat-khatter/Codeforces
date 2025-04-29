#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,m ; cin >> n>> m;
        string s; cin >> s;

        set<ll> s1; // indexes set
        for(ll i=0;i<m;i++){
        ll x; cin >> x;
        s1.insert(x);
        }
        string c; cin >> c;

        multiset<char> s2; // characters set
        map<char , ll> mp;
        for(ll i=0;i<m;i++){
        char x = c[i];
        s2.insert(x);
        mp[x]++;
        }

        for(auto i: s1){
            // getting the minimum element for that index
            char e = *(s2.begin());
            s[i-1] = e;
            mp[e]--;
            if(mp[e]==0) s2.erase(e); // if there are no other characters of same type then delete that charcter
        }

        cout << s << '\n';

    }
    




    return 0;
}