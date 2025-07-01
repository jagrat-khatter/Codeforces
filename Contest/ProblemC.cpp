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
        ll  n; cin >> n;
        vector<ll> v(n);
        set<ll> s1,s2;
        ll mx=lmin,mn=lmax;
        for(auto &i : v) {cin >> i; s1.insert(i);
        mx = max(mx , i);
        mn = min(mn , i);}
        
        string s;
        for(ll i=0;i<n;i++){
            s1.erase(v[i]);

            if(i==0 || i==n-1 || v[i]==mx || v[i]==mn) s.push_back('1');
            else{
                ll s1max = *(--s1.end());
                ll s2min = *(s2.begin());
            //cout << s1max << ' ' << s2min << '\n';
                if(v[i]>s1max && v[i]<s2min) s.push_back('1');
                else if(v[i]>s1max && v[i]>s2min) s.push_back('1');
                else if(v[i]<s1max && v[i]<s2min) s.push_back('1');
                else s.push_back('0');
            }
            
            s2.insert(v[i]);
        }

        cout << s << '\n';
    }
    
    

    return 0;
}