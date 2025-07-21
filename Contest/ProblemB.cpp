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

    ll t; cin >> t;
    while(t--){
        ll n , mx=lmin; cin >> n;
        vector<ll> v(n);
        map<ll,ll> mp;
         
        for(auto & i : v) {cin >> i;}
        sort(v.begin() , v.end());
        ll gmx = v[n-1];// v.pop_back() ;
        for(auto i : v) {mp[i]++;mx = max(mx , i);}
         
        vector<ll> fq(1e5+1);
        for(ll j=mx;j>=0;j--){
            if(j==mx) fq[j]=mp[j];
            else fq[j]=fq[j+1]+mp[j];
        }
        // cout << mx <<' ' <<gmx << '\n' ;
        // for(ll i=0;i<=mx;i++) {
        //     cout << fq[i] << ' ';
        // }
        // for(auto i : v) cout << i << ' ';
        // cout << '\n' ;
        ll ans=0;
        for(ll i=0;i<v.size();i++){
            for(ll j=i+1;j<v.size();j++){
                ll sum = v[i]+v[j];
                
                // now the last element should be greater than gmx-sum and less than sum
                ll l=j+1-1 , r=v.size()-1+1;
                ll req = gmx - sum ;
                while(r-1>l){
                    ll mid = (l+r)/2;
                    if(v[mid]<=req) l=mid;
                    else if(v[mid]>req) r=mid;
                }// take r from this 
                
                ll l2=j+1-1 , r2=v.size()-1+1;
                ll req2 = sum;
                while(r2-1>l2){
                    ll mid = (l2+r2)/2;
                    if(v[mid]<req2) l2=mid;
                    else if(v[mid]>=req2) r2=mid;
                }// take l2 from this 
                
                //cout <<i << ' ' << j << ' ' <<  r << ' ' << l2 << '\n'; 
                if(l2>=r) ans+= l2-r+1 ;
                //if(i==0 && j==1) break;
            }
            //if(i==0) break;
        }

        cout << ans << '\n' ;
        
    }
    
    
    return 0;
}