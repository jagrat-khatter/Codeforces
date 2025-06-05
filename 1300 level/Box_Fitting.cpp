#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll func(ll n){
    ll ct=0;
    while(n!=1){
        ct++;
        n = n/2;
    }
    return ct;
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll power(ll a ,ll b){
    if(b==0) return 1;
    ll value = power(a , b/2);
    if(b%2==0) return value*value;
    else return value*value*a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,w; cin >> n >> w;
        map<ll ,ll> mp; // the key will will be power of 2 value will be frequency
        ll id = lmin;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            ll key = func(x);
            mp[key] ++;
            id = max(id , key);
        }
        vector<ll> v;
        for(ll i=0;i<=id;i++){
            v.push_back(mp[i]); // the index of this vector will be power of 2 and its value will be frequnecy of 2^n
        }
        // for(auto i : v) cout << i << ' ';
        // cout << '\n';
        ll ct=0;
        while(v.size()){
            // initially we have full width of box
            ct++; // if this loop is running this means that there is somethhing to put up in the box
            // for(auto i : v) cout << i << ' ';
            // cout << '\n';
            ll vsz = v.size()-1;
            ll wdt = w;
            for(ll i=vsz;i>=0;i--){
                if(v[i]!=0 && wdt -power(2 , i) >= 0){
                    wdt -= power(2,i);
                    v[i]--;
                    if(v[i]!=0) i++; // try to repeat deletion with same element if possible then happen
                    // otherwise if will be skipped 
                }
            }
            // now clean the array v 
            ll k=vsz;
            while(1 && k>=0){
                if(v[k] == 0){
                    v.pop_back();
                    k--;
                }
                else break;
            }
            
        }
        cout << ct << '\n';
    }





    return 0;
}