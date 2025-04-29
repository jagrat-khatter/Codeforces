#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
ll gcd(ll a, ll b)
{
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
        }
        ll ans1 = v[0] , ans2=v[1]; // initialized ths gcd for even index elements and gcd for odd index elements 
        for(ll i=2;i<n;i++)
        {
            if(i%2==0){
                ans1 = gcd(ans1 , v[i]);
            }
            else ans2= gcd(ans2 , v[i]);
        }
        ll f1=0 , f2=0; // f1=> Checking if gcd of even index elements don't divide any odd index elements
        // f2=> Checking if gcd of odd index elements don't divide any even index elements
        for(ll i=1;i<n;i+=2) // iterating over elemets of odd index
        {
            if(v[i]%ans1 == 0) {f1=1 ; break;}
        }
        if(!f1) {cout << ans1 << '\n'; continue;;}
        for(ll i=0;i<n;i+=2) // iterating over elements of even index
        {
            if(v[i]%ans2 == 0) {f2=1 ; break;}
        }
        if(!f2) {cout << ans2 << '\n' ; continue;}
        else cout << 0 << '\n';
        

    }


    return 0;
}