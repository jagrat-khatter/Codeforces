#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll gcd(ll a, ll b)
{
    if(b==0) return a; // GCD of a and 0 is a 
    else return gcd(b,a%b); // Recursive case
}
ll max(ll a,ll b)
{
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n , sum=0; cin >> n;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
        }
        vector<ll> s;
        s.push_back(v[0]);
        for(ll i=1;i<n;i++)
        {
            s.push_back(v[i]+s[i-1]);
        }
        ll sf = s[n-1] , ans=lmin;
        for(ll i=0;i<n-1;i++){ // all the index less than equal to i are included in first subsegment 
            ll a = s[i];
            ll b = sf - a;
            ans = max (ans , gcd(a,b));
        }

        cout <<  ans <<'\n' ;
        
        
    }


    return 0;
}