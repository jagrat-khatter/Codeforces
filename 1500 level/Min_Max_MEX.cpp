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
bool func(ll target , ll k , vector<ll>& a){
    ll n = a.size();
    if(n==0){
        return true;
    }
     else {
        
        ll segments = 0;
        vector<ll> count(target, 0);
        ll mexValue = 0;
        for (ll i = 0; i < n; ++i) {
		if (a[i] < target) {
			count[a[i]]++;
			while (mexValue < target && count[mexValue] > 0) {
				mexValue++;
			}
		}
		if (mexValue == target) {
			segments++;
			fill(count.begin(), count.end(), 0);
			mexValue = 0;
		}
	}
	return segments >= k;
    }
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
        ll l=0-1 , r=n+1+1;
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