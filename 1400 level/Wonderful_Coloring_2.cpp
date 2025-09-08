#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b , ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,k ; cin >> n >> k;
        set<ll> s; // this will store the number of unique elements 
        map<ll ,ll> ct;// this will store the count of each unique element
        map<ll ,set<ll>> st; // this will give access to set where we'll store the colors that 
        // are associated with element , set corresponding to each element can have a unique color
        // associated only one time
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x ;cin >> x; s.insert(x); ct[x]++;
            v.push_back(x);
        }
        for(auto i : s){
            
            if(ct[i]>=k) {
                for(ll j=1;j<=k;j++){
                    st[i].insert(j);
                }
                for(ll j=1;j<=ct[i]-k;j++){
                    st[i].insert(0);
                }
                ct[i]=0;
            }
        }
        vector<ll> rm;
        for(auto i : s){
            if(ct[i]){
                for(ll j=0;j<ct[i];j++){
                    rm.push_back(i);
                }
            }
        }
        ll len = (ll)(rm.size()/k) * k;
        for(ll j=0;j<len;j++){
            if(((j+1) % k )!=0) st[rm[j]].insert((j+1)%k);
            else  st[rm[j]].insert(k);
        }
        for(ll j=len;j<rm.size();j++){
            st[rm[j]].insert(0);
        }
        // for(auto i: s){
        //     cout << i << '\n';
        //     for(auto j : st[i]){
        //         cout << j << ' ';
        //     }
        //     cout << '\n' ;
        // }
        //cout << 'l' <<'\n' ;
        for(auto i : v){
            // set of i will not be empty
            auto it = (--st[i].end());
            cout << *it << ' ';
            if(distance(st[i].begin() , it)!=0) st[i].erase(*it);
        }
        cout << '\n' ;
    }



    return 0;
}