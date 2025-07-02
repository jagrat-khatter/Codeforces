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
        set<ll> s;
        map<ll ,ll> mp;
        ll mx=lmin;
        for(ll i=0;i<n;i++){
            ll x;cin >> x;
            mp[x]++;
            mx = max(mx , x);
        }
        for(ll i=0;i<=mx+1;i++) s.insert(i);
        
        vector<ll> v(n +1+1, 0); //k=  0 to n-1  what will be number if possible values of MEX
        vector<ll> fq;
        ll sfs =0; // suffix sum
        ll pfs=0; // prefix sum
        for(auto i : s){
            sfs+=mp[i];
            fq.push_back(mp[i]);
        }
        //cout << sfs << '\n';
        vector<pair<ll ,ll>> vp;
        for(ll i=0;i<fq.size();i++){
            sfs -= fq[i] ;
            
            vp.push_back({fq[i] ,  fq[i]+sfs+(pfs-i)}) ;
            pfs += fq[i];
        }
        // for(auto i : fq) cout << i << ' ';
        // cout << '\n';
        //for(auto i : vp) {cout << i.first << ' ' << i.second << '\n';}
        for(auto i : vp){
            v[i.first]++;
            v[i.second+1]--;
            if(i.first == 0) break;
        }
        //for(auto i : v) cout << i << ' ';
        for(ll i=0;i<v.size();i++){
            if(i!=0) v[i] = v[i]+v[i-1];
        }
        for(ll i=0;i<v.size()-1;i++){
            cout << v[i] << ' ';
        }
        cout << '\n';

    }
    
    

    return 0;
}