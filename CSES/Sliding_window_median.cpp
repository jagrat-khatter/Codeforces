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
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k ; cin >> n >> k;
    vector<ll> v(n);
    for(auto &i : v) cin >> i;

    vector<pair<ll,ll>> vp;
    for(ll i=0;i<k;i++){
        vp.push_back({v[i] , i});
    }
    sort(vp.begin() , vp.end());
    set<pair<ll,ll>> s1,s2;
    for(ll i=0;i<vp.size();i++){
        if(i<((k+2-1)/ 2)) s1.insert(vp[i]);
        else s2.insert(vp[i]);
    }

    for(ll i=0;i<=n-k;i++){
        if(i!=0){
            ll ps1 = s1.size();
            ll ps2 = s2.size();
            
            s1.erase({v[i-1] , i-1}); // we don't know from which set s1 and s2 element will get erased
            s2.erase({v[i-1] , i-1});
            ll ne = v[i+k-1];
            if(ps1 != s1.size()){// now first set has an empty space
                s2.insert({ne , i+k-1});// we'll first insert the element in s2
                // now well take out the minimum element from s2
                pair<ll,ll> smle = *(s2.begin());// this element has to be in first set 
                s2.erase(smle);
                s1.insert(smle);
            }
            else {// ther is a n empty space in s2
                // so we will take largest element from s1 after considering addition of new element
                s1.insert({ne , i+k-1});

                pair<ll,ll> le = *(--s1.end());// this element has to be removed from s1
                s1.erase(le);
                s2.insert(le);
            }
            
        }

        pair<ll,ll> el = *(--s1.end());
        cout << el.first << ' ';
    }

    return 0;
}