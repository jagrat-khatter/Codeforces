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
    while(t--){
        ll n; cin >> n;
        vector<ll> v;
        map<ll , ll> mp; // first space we'll store element value , at second space we'll store index
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back(x);
            mp[x] = i+1;
        }
        sort(v.begin() , v.end());
        // now finding all the pairs for which product of elements is less than equal to n + n-1
        ll l, r;
        ll mn = n + n-1;
        ll ct=0;
        for(ll i=0;i<n;i++){
            l=i;// now we want index of element just <= mn / v[i]
            ll e = mn / v[i];
            ll p=0-1 , q = n-1+1;
            while(q-1>p){
                ll mid =(p+q)/2;
                if(v[mid]<=e) p=mid;
                else q=mid;
            } 
            r = p;
            // cout << l << ' ' << r << '\n';
            if(r>l) {
                for(ll j=l+1;j<=r;j++){
                    if(mp[v[j]] + mp[v[l]] == v[j] * v[l]) ct++;
                }
            }
            else
                break;
        }
        cout << ct << '\n';

    }



    return 0;
}