#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        string st; cin >> st;
        
        set<char> s;
        map<char , ll> mp;
        for(auto i : st){
            mp[i]++;
            s.insert(i);
        }
        ll fg=0;
        for(ll i=1;i<st.size()-1;i++){
            char e = st[i];
            mp[e]--;
            if(mp[e]==0) s.erase(e);
            if(s.find(e) != s.end()) fg=1;

            mp[e]++;
            s.insert(e);
        }

        if(fg) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    
    

    return 0;
}