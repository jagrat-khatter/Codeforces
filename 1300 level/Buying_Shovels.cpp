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
        ll n,k ; cin >> n >> k;
        set<ll> s;
        for(ll i=1;i*i<=n;i++){
            if(n%i==0){
                if(n/i <= k) s.insert(n/i);
                if(i <= k) s.insert(i);
            }
            // all divisors of n which are less than equal to k
        }


        cout << n / *(--s.end()) << '\n';
        // s will never be empty 
        
    }




    return 0;
}