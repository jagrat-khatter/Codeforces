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
    vector<ll> v;
    for(ll i=0;i<n;i++){
        ll x; cin >> x;
        v.push_back(x);
    }

    ll lfs=0 , rfs =0 ;
    vector<pair<ll ,ll>> vp;
    for(ll i=0;i<k;i++){

        vp.push_back({v[i] , i});
    }
    sort(vp.begin() , vp.end());
    set<pair<ll,ll>> s1,s2;
    for(ll i=0;i<k;i++){
        if(i<((k+2-1)/2)){
            s1.insert(vp[i]);
            lfs += vp[i].first;
        }
        else {s2.insert(vp[i]);
        rfs += vp[i].first;}
    }
    for(ll i=0;i<=n-k;i++){
        if(i!=0){
            ll ps1 = s1.size();
            ll ps2 = s2.size();
            s1.erase({v[i-1] , i-1});// we dont know from which set it will be removed
            s2.erase({v[i-1] , i-1});
            
            ll ne = v[i+k-1];
            if(ps1 != s1.size()){
                lfs -= v[i-1];
                // first well push the element in set 2 and then extract the smallest element of set 2
                s2.insert({ne , i+k-1});
                rfs += ne;
                pair<ll,ll> smle = *(s2.begin());
                s2.erase(smle);
                rfs -= smle.first ;
                s1.insert(smle);
                lfs += smle.first;
            }
            else{
                rfs -= v[i-1];

                s1.insert({ne , i+k-1});
                lfs += ne;
                pair<ll,ll> le = *(--s1.end());
                s1.erase(le);
                lfs -= le.first;
                s2.insert(le);
                rfs += le.first;
            }
        }
        pair<ll,ll> el= *(--s1.end()) ;
        ll md = el.first ;
        
        if(k%2==0){
            cout << rfs - (k/2)*md  + ((k/2)-1)*md - (lfs-md) << ' ';
        }else{
            cout << rfs - (k/2)*md + (k/2)*md - (lfs-md) << ' ';
        }
    }

    return 0;
}