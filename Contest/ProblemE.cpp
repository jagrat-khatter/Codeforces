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
bool func(ll n , ll k , vector<ll>& v){
    ll ct=0;
    if(n==0){
        for(auto i :v){if(i==0) ct++;}
    }
    else {
        ll sum = (n)*(n-1)/2;
        map<ll ,ll> mp;
        ll sum2=0;
        ll fg=0;
        for(auto x : v){
            if(x<n){
                if(mp[x]==0) sum2 +=x;
                if(x==0) fg=1;
                mp[x]++;
            }
            if(sum==sum2 && fg){
                ct++;
                sum2=0;
                fg=0;
                for(ll i=0;i<n;i++) mp[i]=0;
            }
        }
    }
    
    //cout << ct <<'c'<< '\n';
    return (ct>=k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin>> t;
    while(t--){
        ll n,k , mx=lmin; cin >> n >> k;
        vector<ll> v(n);
        for(auto &i : v) {cin >> i;
            if(i>mx) mx=i;
        }
        
        // for(auto i : vb) cout << i << ' ';
        // cout << '\n'; 
        ll l=0-1 , r=mx+1+1;
        while(r-1>l){
            ll mid=(l+r)/2;
            //cout << l << ' ' << r << ' ' << vb[mid] << '\n';
            if(func(mid ,k , v)) l=mid;
            else r=mid;
            //cout << vb[mid] << ' ' << func(vb[mid] ,k , v) << '\n';
            //cout << l << ' ' << r << '\n';
        }
        
        if(l!=-1) cout << l << '\n';
        else cout << 0 << '\n';
        
    }
    
    

    return 0;
}